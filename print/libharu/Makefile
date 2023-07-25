# $NetBSD: Makefile,v 1.3 2023/07/25 12:30:28 thor Exp $

DISTNAME=	libharu-2.4.3
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GITHUB:=libharu/}
GITHUB_TAG=	v${PKGVERSION_NOREV}
DIST_SUBDIR=	libharu

MAINTAINER=	thomas.orgis@uni-hamburg.de
HOMEPAGE=	https://github.com/libharu/libharu/
COMMENT=	Software library for generating PDF
LICENSE=	zlib

USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DLIBHPDF_STATIC=OFF

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
post-install: fix-darwin-install-name
fix-darwin-install-name:
	install_name_tool -id ${PREFIX}/lib/libhpdf.dylib \
	    ${DESTDIR}${PREFIX}/lib/libhpdf.dylib
.endif

.include "../../devel/cmake/build.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
