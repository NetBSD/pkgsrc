# $NetBSD: Makefile,v 1.54 2020/06/05 12:49:12 jperkin Exp $

PKGNAME=	${DISTNAME:S/ffmpeg/ffmpeg3/}
PKGREVISION=	8
MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ffmpeg.org/
COMMENT=	Decoding, encoding and streaming software (v3.x)

CONFIGURE_ARGS+=	--enable-avfilter
CONFIGURE_ARGS+=	--enable-avresample
CONFIGURE_ARGS+=	--enable-postproc
CONFIGURE_ARGS+=	--enable-rpath
CONFIGURE_ARGS+=	--disable-ffplay

INSTALLATION_DIRS=	lib/ffmpeg3 share/doc/ffmpeg3 share/examples/ffmpeg3

CONF_FILES+=	${PREFIX}/share/examples/ffmpeg3/ffserver.conf \
		${PKG_SYSCONFDIR}/ffserver.conf

.include "../../mk/bsd.prefs.mk"

.if !empty(USE_CROSS_COMPILE:M[yY][eE][sS])
CONFIGURE_ARGS+=	--enable-cross-compile
CONFIGURE_ARGS+=	--host-cc=${NATIVE_CC:Q}
CONFIGURE_ARGS+=	--host-ld=${NATIVE_CC:Q}
CONFIGURE_ARGS+=	--target-os=${LOWER_OPSYS}
.endif

PRINT_PLIST_AWK+=	/html/ { $$0 = "$${PLIST.doc}" $$0 }
PRINT_PLIST_AWK+=	/opencl/ { $$0 = "$${PLIST.opencl}" $$0 }

TEST_TARGET=	check

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt \
		${DESTDIR}${PREFIX}/share/doc/ffmpeg3
	${INSTALL_DATA} ${WRKSRC}/doc/ffserver.conf \
		${DESTDIR}${PREFIX}/share/examples/ffmpeg3

.include "options.mk"

.include "../../mk/compiler.mk"

# disable asm on i386 for non-gcc and gcc < 4.2, or to avoid text relocations
.if ${MACHINE_ARCH} == "i386"
.  if !empty(MACHINE_PLATFORM:MDarwin-*-i386) \
   || !empty(MACHINE_PLATFORM:MSunOS-*-i386) \
   || !empty(MACHINE_PLATFORM:MNetBSD-*-i386) \
   || !empty(CC_VERSION:Mgcc-[123]*) \
   || !empty(CC_VERSION:Mgcc-4.[01].*) \
   || empty(CC_VERSION:Mgcc*)
CONFIGURE_ARGS+=	--disable-asm
.  elif !empty(CC_VERSION:Mgcc-[456].*)
CFLAGS+=		-mstackrealign -mpreferred-stack-boundary=4
.  endif
.endif

# configure script uses uname -m to detect arch, as opposed to uname -p in
# GNU/configure. Unable to detect NetBSD/macppc hosts correctly.
CONFIGURE_ARGS+=	--arch=${MACHINE_ARCH}

.include "../../multimedia/ffmpeg3/Makefile.common"
