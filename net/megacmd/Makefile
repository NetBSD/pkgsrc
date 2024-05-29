# $NetBSD: Makefile,v 1.3 2024/05/29 16:33:58 adam Exp $

DISTNAME=	megacmd-1.6.3
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=meganz/}
GITHUB_PROJECT=	MEGAcmd
GITHUB_TAG=	${PKGVERSION_NOREV}_Linux
SDK_VERSION=	v4.17.1d

GITHUB_SUBMODULES=	meganz sdk ${SDK_VERSION} sdk

MAINTAINER=	kikadf.01@gmail.com
HOMEPAGE=	https://mega.io/
COMMENT=	CLI and scriptable application to access MEGA
# MEGAcmd: GPLv3, SDK: BSD 2-clause
LICENSE=	gnu-gpl-v3 AND 2-clause-bsd

USE_LANGUAGES+=		c c++
USE_CXX_FEATURES+=	filesystem
USE_LIBTOOL=		yes
USE_TOOLS+=		autoreconf autoconf automake
GNU_CONFIGURE=		yes
REPLACE_SH=		src/client/mega-*
CXXFLAGS+=		-DCRYPTOPP_DISABLE_ASM -std=c++17
BUILDLINK_TRANSFORM+=	rm:-std=c++11

CONFIGURE_ARGS+=	--disable-examples
CONFIGURE_ARGS+=	--disable-java
CONFIGURE_ARGS+=	--disable-php
CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--disable-chat
CONFIGURE_ARGS+=	--without-freeimage
CONFIGURE_ARGS+=	--without-termcap
CONFIGURE_ARGS+=	--without-ffmpeg
CONFIGURE_ARGS+=	--without-libraw
CONFIGURE_ARGS+=	--without-libzen
CONFIGURE_ARGS+=	--without-libmediainfo
CONFIGURE_ARGS+=	--enable-gcc-hardening

CHECK_PORTABILITY_SKIP+=	sdk/bindings/ios/3rdparty/*.sh

pre-configure:
	cd ${WRKSRC} && ${SH} autogen.sh

post-install:
	${MV} ${DESTDIR}${PREFIX}/share/bash-completion/completions/megacmd_completion.sh \
		${DESTDIR}${PREFIX}/share/bash-completion/completions/megacmd

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/libuv/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../net/libcares/buildlink3.mk"
.include "../../security/crypto++/buildlink3.mk"
.include "../../security/libsodium/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
