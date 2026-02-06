# $NetBSD: Makefile,v 1.17 2026/02/06 10:05:35 wiz Exp $

DISTNAME=	megacmd-2.1.1
PKGREVISION=	4
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=meganz/}
GITHUB_PROJECT=	MEGAcmd
GITHUB_TAG=	${PKGVERSION_NOREV}_Linux
SDK_VERSION=	v9.1.1

GITHUB_SUBMODULES=	meganz sdk ${SDK_VERSION} sdk

MAINTAINER=	kikadf.01@gmail.com
HOMEPAGE=	https://mega.io/
COMMENT=	CLI and scriptable application to access MEGA
# MEGAcmd: GPLv3, SDK: BSD 2-clause
LICENSE=	gnu-gpl-v3 AND 2-clause-bsd

TOOL_DEPENDS+=	git-base-[0-9]*:../../devel/git-base

USE_LANGUAGES+=		c c++
USE_CXX_FEATURES+=	filesystem
FORCE_CXX_STD=		c++17
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
REPLACE_SH=		src/client/mega-*
CXXFLAGS+=		-DCRYPTOPP_DISABLE_ASM

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_CONFIGURE_ARGS+=	-DFULL_REQS=OFF
CMAKE_CONFIGURE_ARGS+=	-DUSE_MEDIAINFO=OFF
CMAKE_CONFIGURE_ARGS+=	-DUSE_FREEIMAGE=OFF
CMAKE_CONFIGURE_ARGS+=	-DUSE_FFMPEG=OFF
CMAKE_CONFIGURE_ARGS+=	-DUSE_PDFIUM=OFF
CMAKE_CONFIGURE_ARGS+=	-DWITH_FUSE=OFF
CMAKE_CONFIGURE_ARGS+=	-DVCPKG_ROOT=""

CHECK_PORTABILITY_SKIP+=	sdk/bindings/ios/3rdparty/*.sh

INSTALLATION_DIRS+=	share/doc/megacmd

post-install:
	${MV} ${DESTDIR}${PREFIX}/share/bash-completion/completions/megacmd_completion.sh \
		${DESTDIR}${PREFIX}/share/bash-completion/completions/megacmd
	${INSTALL_DATA} ${FILESDIR}/README ${DESTDIR}${PREFIX}/share/doc/megacmd

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/libuv/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../net/libcares/buildlink3.mk"
BUILDLINK_API_DEPENDS.cryptopp+=	cryptopp>=8.7.0nb1
.include "../../security/crypto++/buildlink3.mk"
.include "../../security/libsodium/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
