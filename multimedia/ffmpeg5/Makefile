# $NetBSD: Makefile,v 1.29 2024/01/26 03:17:07 riastradh Exp $

PKGNAME=	${DISTNAME:S/ffmpeg/ffmpeg5/}
PKGREVISION=	1
MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ffmpeg.org/
COMMENT=	Decoding, encoding and streaming software (v5.x)

CONFIGURE_ARGS+=	--enable-avfilter
CONFIGURE_ARGS+=	--enable-postproc
CONFIGURE_ARGS+=	--disable-ffplay

INSTALLATION_DIRS=	lib/ffmpeg5 share/doc/ffmpeg5

.include "../../mk/bsd.prefs.mk"

.if ${_USE_RPATH:tl} != "no"
CONFIGURE_ARGS+=	--enable-rpath
.endif

.if ${USE_CROSS_COMPILE:U:tl} == yes
CONFIGURE_ARGS+=	--enable-cross-compile
CONFIGURE_ARGS+=	--host-cc=${NATIVE_CC:Q}
CONFIGURE_ARGS+=	--host-ld=${NATIVE_CC:Q}
CONFIGURE_ARGS+=	--target-os=${LOWER_OPSYS}
.  include "../../mk/endian.mk"
.  if ${MACHINE_ENDIAN} == "big"
CONFIGURE_ENV+=		bigendian=yes
.  endif
.endif

PRINT_PLIST_AWK+=	/html/ { $$0 = "$${PLIST.doc}" $$0 }

TEST_TARGET=	check

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt \
		${DESTDIR}${PREFIX}/share/doc/ffmpeg5

.include "options.mk"

# disable asm on i386 to avoid text relocations
.if ${MACHINE_ARCH} == "i386"
CONFIGURE_ARGS+=	--disable-asm
.endif

# configure script uses uname -m to detect arch, as opposed to uname -p in
# GNU/configure. Unable to detect NetBSD/macppc hosts correctly.
CONFIGURE_ARGS+=	--arch=${MACHINE_ARCH}

.include "../../multimedia/ffmpeg5/Makefile.common"
.include "../../mk/bsd.pkg.mk"
