# $NetBSD: Makefile,v 1.3 2011/03/12 11:00:01 tron Exp $

DISTNAME=	libvpx-v0.9.6
PKGNAME=	${DISTNAME:S/-v/-/}
CATEGORIES=	multimedia
MASTER_SITES=	http://webm.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://code.google.com/p/webm/
COMMENT=	On2 VP8 library from Google
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=	YES
USE_TOOLS+=	gmake bash:build perl:build

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
BUILD_DEPENDS+=		yasm-[0-9]*:../../devel/yasm
.endif

HAS_CONFIGURE=	YES
USE_LANGUAGES=	c c++

REPLACE_BASH=		configure \
			build/make/version.sh \
			build/make/gen_asm_deps.sh \
			examples/gen_example_text.sh \
			examples/gen_example_code.sh

CONFIGURE_ARGS+=	--enable-pic \
			--disable-postproc \
			--enable-runtime-cpu-detect \
			--prefix=${PREFIX}

.if ${OPSYS} == "Darwin"
BUILDLINK_TRANSFORM+=	rm:-lrt

.  if ${MACHINE_ARCH} == "i386"
.    if empty(OS_VERSION:M8.*)
CONFIGURE_ARGS+=	--target=x86-darwin9-gcc
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
