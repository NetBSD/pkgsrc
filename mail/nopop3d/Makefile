# $NetBSD: Makefile,v 1.1 2020/10/30 10:19:22 schmonz Exp $

DISTNAME=		notqmail-1.08
PKGNAME=		nopop3d-20201030
CATEGORIES=		mail
MASTER_SITES=		# empty

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		# none
COMMENT=		POP3 server for when you don't want mail
LICENSE=		public-domain

BUILD_TARGET=		${PKGBASE}

DJB_RESTRICTED=		no

INSTALLATION_DIRS=	bin

post-extract:
	${CP} ${FILESDIR}/${PKGBASE}.c ${WRKSRC}
	${CAT} ${FILESDIR}/${PKGBASE}.mk >> ${WRKSRC}/${MAKE_FILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PKGBASE} ${DESTDIR}${PREFIX}/bin

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
