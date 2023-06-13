# $NetBSD: Makefile,v 1.1 2023/06/13 13:14:38 bacon Exp $

DISTNAME=	desktop-installer-0.8.0.23
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=outpaddling/}
GITHUB_TAG=	2cda0d4e09e98b935c9a6fea785b0d95860daa88

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://github.com/outpaddling/desktop-installer/tree/master/NetBSD
COMMENT=	Quickly configure a NetBSD desktop system
LICENSE=	2-clause-bsd

# Script is NetBSD-specific in many ways
ONLY_FOR_PLATFORM=	NetBSD-*-*

SUBST_CLASSES+=	tk
SUBST_STAGE.tk=	pre-configure
SUBST_SED.tk=	-e 's|/usr/pkg/bin/wish|${PREFIX}/bin/wish|g'
SUBST_FILES.tk=	NetBSD/XDM/xdmshutdown

USE_TOOLS+=	pax
NO_BUILD=	yes

DEPENDS=	auto-admin>=0.7.13:../../sysutils/auto-admin

.include "../../mk/bsd.prefs.mk"

DATADIR=		${PREFIX}/share/${PKGBASE}
INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man1 share/${PKGBASE}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${OPSYS}/${PKGBASE} ${DESTDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/Scripts/battery-shutdown.sh ${DESTDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/NetBSD/${PKGBASE}.man \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${PKGBASE}.1
	${MKDIR} ${DESTDIR}${DATADIR}
	cd ${WRKSRC}/Common && pax -rw . ${DESTDIR}${DATADIR}
	cd ${WRKSRC}/NetBSD && pax -rw XDM ${DESTDIR}${DATADIR}

.include "../../mk/bsd.pkg.mk"
