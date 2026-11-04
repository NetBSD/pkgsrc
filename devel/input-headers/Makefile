# $NetBSD: Makefile,v 1.4 2026/11/04 11:24:03 kikadf Exp $

.include "../../devel/libopeninput/Makefile.common"

PKGNAME=	input-headers-${VERSION}
PKGREVISION=	1
COMMENT=	Input headers from libopeninput

USE_TOOLS+=	pax

INSTALLATION_DIRS+=	include/linux

do-configure:

do-build:

do-install:
	${RUN} cd ${WRKSRC}/include/linux && \
		${FIND} . -type f -name "*.h" -print | pax -rw -pmp ${DESTDIR}${PREFIX}/include/linux

.include "../../mk/bsd.pkg.mk"
