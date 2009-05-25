# $NetBSD: Makefile,v 1.19 2009/05/25 20:56:38 drochner Exp $

SNAPSHOT_DATE=		20090326

DISTNAME=		x264-snapshot-${SNAPSHOT_DATE}-2245
PKGNAME=		x264-devel-${SNAPSHOT_DATE}
CATEGORIES=		multimedia
MASTER_SITES=		ftp://ftp.videolan.org/pub/videolan/x264/snapshots/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://www.videolan.org/developers/x264.html
COMMENT=		GPL licensed H.264 encoder

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

.if exists(/usr/include/stdlib.h) && ${OPSYS} != Linux # XXX should be fine
CFLAGS+=	-DHAVE_STDLIB_H
.endif

.if ${MACHINE_ARCH} == "i386"
.  if ${OPSYS} == "Darwin"
CONFIGURE_ARGS+=	--disable-asm
.  else
BUILD_DEPENDS+=	yasm>=0.4.0:../../devel/yasm
.  endif
.elif ${MACHINE_ARCH} == "x86_64"
CONFIGURE_ARGS+=	--disable-asm
.endif

USE_TOOLS+=		gmake
USE_LIBTOOL=		yes

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-pic	# uses libtool's -prefer-pic
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--disable-mp4-output	# needs GPAC, not in pkgsrc
MAKE_ENV+=		SH=${SH:Q}

BUILD_TARGET=		default
BUILDLINK_TRANSFORM+=	rm:-O4	# XXX does this mean anything to any compiler?
REPLACE_SH=		strip_fopt.sh version.sh

.include "../../mk/dlopen.buildlink3.mk"

CHECK_BUILTIN.pthread:=	yes
.include "../../mk/pthread.builtin.mk"
CHECK_BUILTIN.pthread:=	no

.if !empty(USE_BUILTIN.pthread:M[Yy][Ee][Ss])
X264_BUILD_THREADS_SUPPORT=	yes
.else
X264_BUILD_THREADS_SUPPORT=	${DLOPEN_REQUIRE_PTHREADS}
.endif

.include "options.mk"

post-extract:
	${CP} ${FILESDIR}/strip_fopt.sh ${WRKSRC}/ && \
	${CHMOD} +x ${WRKSRC}/strip_fopt.sh

.include "../../mk/bsd.pkg.mk"
