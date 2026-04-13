# $NetBSD: Makefile,v 1.1 2026/04/13 15:24:45 kikadf Exp $

.include "../../devel/libopeninput/Makefile.common"

PKGNAME=	input-headers-${VERSION}
COMMENT=	Input headers from libopeninput

USE_TOOLS+=	pax

INSTALLATION_DIRS+=	include/linux

do-configure:

do-build:

do-install:
	${RUN} cd ${WRKSRC}/include/linux && \
		${FIND} . -type f -name "*.h" -print | pax -rw -pmp ${DESTDIR}${PREFIX}/include/linux

.include "../../mk/bsd.pkg.mk"
