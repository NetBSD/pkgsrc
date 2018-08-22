# $NetBSD: Makefile,v 1.18 2018/08/22 09:45:44 wiz Exp $
#

DISTNAME=		mirmon-2.11
PKGREVISION=		1
CATEGORIES=		misc
MASTER_SITES=		http://www.staff.science.uu.nl/~penni101/mirmon/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.staff.science.uu.nl/~penni101/mirmon/
COMMENT=		Monitor the state of mirror servers
LICENSE=		apache-1.1

REPLACE_PERL+=		mirmon
USE_TOOLS+=		perl:run pod2man
USE_LANGUAGES=		# empty

EG_DIR=			${PREFIX}/share/examples/mirmon
MIRMONDIR=		${PREFIX}/share/mirmon

SUBST_CLASSES+=		mirmon1
SUBST_STAGE.mirmon1=	pre-configure
SUBST_FILES.mirmon1=	mirmon
SUBST_SED.mirmon1+=	-e s!/etc/!${PKG_SYSCONFDIR}/!g
SUBST_SED.mirmon1+=	-e s!/sw/!${PREFIX}/!g

SUBST_CLASSES+=		mirmon2
SUBST_STAGE.mirmon2=	pre-configure
SUBST_FILES.mirmon2=	${WRKDIR}/mirmon.conf
SUBST_SED.mirmon2+=	-e s!@@MIRMONDIR@@!${MIRMONDIR}!g

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/examples/mirmon \
			share/mirmon/icons

post-extract:
	${CP} ${FILESDIR}/mirmon.conf ${WRKDIR}

do-build:
	cd ${WRKSRC} && ${POD2MAN} mirmon > ${WRKDIR}/mirmon.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mirmon ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/mirmon.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKDIR}/mirmon.conf ${DESTDIR}${EG_DIR}
	${INSTALL_DATA} ${WRKSRC}/countries.list ${DESTDIR}${MIRMONDIR}
	cd ${WRKSRC}/icons && ${INSTALL_DATA} * ${DESTDIR}${MIRMONDIR}/icons

.include "../../mk/bsd.pkg.mk"
