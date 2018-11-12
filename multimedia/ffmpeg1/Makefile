# $NetBSD: Makefile,v 1.15 2018/11/12 03:52:36 ryoon Exp $

PKGNAME=	${DISTNAME:S/ffmpeg/ffmpeg1/}
PKGREVISION=	10
MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ffmpeg.mplayerhq.hu/
COMMENT=	Decoding, encoding and streaming software (v1.x)

CONFIGURE_ARGS+=	--enable-avfilter
#CONFIGURE_ARGS+=	--enable-avfilter-lavf
CONFIGURE_ARGS+=	--enable-postproc
CONFIGURE_ARGS+=	--host-cflags=${CFLAGS:Q}
CONFIGURE_ARGS+=	--host-ldflags=${LDFLAGS:Q}

INSTALLATION_DIRS=	lib share/examples/ffmpeg1 share/doc/ffmpeg1

CONF_FILES+=	${PREFIX}/share/examples/ffmpeg1/ffserver.conf \
		${PKG_SYSCONFDIR}/ffserver.conf

# Needs to come before bsd.prefs.mk or compiler.mk, USE_LIBTOOL is set too late.
USE_GCC_RUNTIME=	yes

.include "../../mk/bsd.prefs.mk"

.if !empty(USE_CROSS_COMPILE:M[yY][eE][sS])
CONFIGURE_ARGS+=	--enable-cross-compile
CONFIGURE_ARGS+=	--target-os=${LOWER_OPSYS}
CONFIGURE_ARGS+=	--arch=${MACHINE_ARCH}
CONFIGURE_ARGS+=	--host-cc=${NATIVE_CC:Q}
CONFIGURE_ARGS+=	--host-ld=${NATIVE_CC:Q}
.endif

TEST_TARGET=	check

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt \
		${DESTDIR}${PREFIX}/share/doc/ffmpeg1
	${INSTALL_DATA} ${WRKSRC}/doc/ffserver.conf \
		${DESTDIR}${PREFIX}/share/examples/ffmpeg1

.include "options.mk"

.include "../../mk/compiler.mk"

# disable asm on i386 for non-gcc and gcc < 4.2
.if ${MACHINE_ARCH} == "i386"
.  if !empty(MACHINE_PLATFORM:MDarwin-*-i386) \
   || !empty(MACHINE_PLATFORM:MSunOS-*-i386) \
   || !empty(CC_VERSION:Mgcc-[123]*) \
   || !empty(CC_VERSION:Mgcc-4.[01].*) \
   ||  empty(CC_VERSION:Mgcc*)
CONFIGURE_ARGS+=	--disable-asm
.  elif !empty(CC_VERSION:Mgcc-[456].*)
CFLAGS+=		-mstackrealign -mpreferred-stack-boundary=4
.  endif
.endif

.include "../../multimedia/ffmpeg1/Makefile.common"
