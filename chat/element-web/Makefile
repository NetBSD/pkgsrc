# $NetBSD: Makefile,v 1.43 2026/04/01 23:46:58 js Exp $

DISTNAME=	element-v${PKGVERSION_NOREV}
PKGNAME=	element-web-1.12.12
CATEGORIES=	chat
# Using the normal GitHub fetching only works for one distfile, even when
# trying to hack around it.
MASTER_SITES=	https://github.com/element-hq/element-web/releases/download/v${PKGVERSION_NOREV}/
DISTFILES=	${DISTNAME}.tar.gz
DISTFILES+=	${DISTNAME}.tar.gz.asc

MAINTAINER=	js@NetBSD.org
HOMEPAGE=	https://element.io/
COMMENT=	Matrix web client
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/element-v${PKGVERSION_NOREV}
USE_LANGUAGES=	# none
USE_TOOLS+=	pax
NO_BUILD=	yes

INSTALLATION_DIRS+=	share/element-web

do-install:
	cd ${WRKSRC} && pax -rw . ${DESTDIR}${PREFIX}/share/element-web

verify-signature:
	gpgv --keyring ${FILESDIR}/gpgkey-element.gpg \
		${DISTDIR}/${DISTNAME}.tar.gz.asc \
		${DISTDIR}/${DISTNAME}.tar.gz

.include "../../mk/bsd.pkg.mk"
