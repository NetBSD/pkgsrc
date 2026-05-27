# $NetBSD: Makefile,v 1.2 2026/05/27 17:15:13 kikadf Exp $

.include "../../devel/libopeninput/Makefile.common"

PKGREVISION=	1
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
