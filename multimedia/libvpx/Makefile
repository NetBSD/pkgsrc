# $NetBSD: Makefile,v 1.8 2011/08/07 17:20:09 ryoon Exp $

DISTNAME=	libvpx-v0.9.7
PKGNAME=	${DISTNAME:S/-v/-/}
CATEGORIES=	multimedia
MASTER_SITES=	http://webm.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://code.google.com/p/webm/
COMMENT=	On2 VP8 library from Google
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake bash:build perl:build
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-postproc
CONFIGURE_ARGS+=	--enable-pic
CONFIGURE_ARGS+=	--enable-runtime-cpu-detect
CONFIGURE_ARGS+=	--prefix=${PREFIX}

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
BUILD_DEPENDS+=		yasm-[0-9]*:../../devel/yasm
.endif

REPLACE_BASH=		configure \
			build/make/version.sh \
			build/make/gen_asm_deps.sh \
			examples/gen_example_text.sh \
			examples/gen_example_code.sh

.if ${OPSYS} == "Darwin"
.  if ${MACHINE_ARCH} == "i386"
.    if !empty(OS_VERSION:M10.*)
CONFIGURE_ARGS+=	--target=x86-darwin10-gcc
.    elif !empty(OS_VERSION:M9.*)
CONFIGURE_ARGS+=	--target=x86-darwin10-gcc
.    else
CONFIGURE_ARGS+=	--target=x86-darwin8-gcc
.    endif
.  endif
.endif

BUILD_TARGET=	# none

post-extract:
	${CP} ${FILESDIR}/strip_fPIC.sh ${WRKSRC}

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
