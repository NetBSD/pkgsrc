# $NetBSD: Makefile,v 1.5 2026/02/01 09:02:19 wiz Exp $

DISTNAME=		qconfirm-0.14.3
CATEGORIES=		mail
MASTER_SITES=		https://smarden.org/qconfirm/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://smarden.org/qconfirm/
COMMENT=		Request delivery confirmation for mail
LICENSE=		modified-bsd

DEPENDS+=		daemontools-[0-9]*:../../sysutils/daemontools
DEPENDS+=		qmail-[0-9]*:../../mail/qmail

DJB_SLASHPACKAGE=	yes

WRKSRC=			${WRKDIR}/mail/${DISTNAME}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

post-extract:
	cd ${WRKSRC}/src \
		&& ${MV} getline.h qconfirm_getline.h \
		&& ${MV} getline.c qconfirm_getline.c

do-install:
	cd ${WRKSRC} \
		&& ${INSTALL_PROGRAM} command/* ${DESTDIR}${PREFIX}/bin \
		&& ${INSTALL_MAN} man/*.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
