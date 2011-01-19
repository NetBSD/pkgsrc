# $NetBSD: Makefile,v 1.1.1.1 2011/01/19 21:15:51 ryoon Exp $
#

DISTNAME=	libvpx-v0.9.5
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

BUILD_TARGET=	# none

post-extract:
	${CP} ${FILESDIR}/strip_fPIC.sh ${WRKSRC}

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
