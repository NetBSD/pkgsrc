# $NetBSD: Makefile,v 1.39 2026/10/26 22:46:43 drixter Exp $

DISTNAME=		upx-5.2.1
PKGREVISION=		1
CATEGORIES=		archivers
MASTER_SITES=		${MASTER_SITE_GITHUB:=upx/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

GITHUB_SUBMODULES+=	upx upx-vendor-bzip2 v${PKGVERSION_NOREV}-upx-vendor vendor/bzip2
GITHUB_SUBMODULES+=	upx upx-vendor-doctest v${PKGVERSION_NOREV}-upx-vendor vendor/doctest
GITHUB_SUBMODULES+=	upx upx-vendor-lzma-sdk v${PKGVERSION_NOREV}-upx-vendor vendor/lzma-sdk
GITHUB_SUBMODULES+=	upx upx-vendor-ucl v${PKGVERSION_NOREV}-upx-vendor vendor/ucl
GITHUB_SUBMODULES+=	upx upx-vendor-valgrind v${PKGVERSION_NOREV}-upx-vendor vendor/valgrind
GITHUB_SUBMODULES+=	upx upx-vendor-zlib v${PKGVERSION_NOREV}-upx-vendor vendor/zlib
GITHUB_SUBMODULES+=	upx upx-vendor-zstd v${PKGVERSION_NOREV}-upx-vendor vendor/zstd

MAINTAINER=		drixter@e-utp.net
HOMEPAGE=		https://upx.github.io/
COMMENT=		Ultimate packer for executables
LICENSE=		gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_TOOLS+=		cmake gmake perl pod2man pod2html pod2text

NO_CONFIGURE=		yes

MAKE_ENV+=		PREFIX=${PREFIX}
MAKE_ENV+=		UPX_UCLDIR=${PREFIX}
MAKE_FLAGS+=		CXXFLAGS_WERROR=

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/upx

BUILDLINK_TRANSFORM+=		rm:-mcpu=i686
BUILDLINK_TRANSFORM+=		rm:-Werror
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,-Map
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,upx.map

do-build:
	${RUN} cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} release

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/release/upx ${DESTDIR}${PREFIX}/bin/upx
	${INSTALL_MAN} ${WRKSRC}/doc/upx.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/doc/upx-doc.txt ${DESTDIR}${PREFIX}/share/doc/upx
	${INSTALL_DATA} ${WRKSRC}/doc/upx-doc.html ${DESTDIR}${PREFIX}/share/doc/upx


.include "../../mk/bsd.pkg.mk"
