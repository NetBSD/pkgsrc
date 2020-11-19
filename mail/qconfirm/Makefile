# $NetBSD: Makefile,v 1.4 2020/11/19 09:35:42 schmonz Exp $

DISTNAME=		qconfirm-0.14.3
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://smarden.org/qconfirm/
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
