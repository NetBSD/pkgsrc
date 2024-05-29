# $NetBSD: Makefile,v 1.5 2024/05/29 16:33:42 adam Exp $

PKGNAME=	${DISTNAME:S/ffmpeg/ffmpeg7/}
PKGREVISION=	1
MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ffmpeg.org/
COMMENT=	Decoding, encoding and streaming software (v7.x)

CONFIGURE_ARGS+=	--enable-avfilter
CONFIGURE_ARGS+=	--enable-postproc
CONFIGURE_ARGS+=	--disable-ffplay

INSTALLATION_DIRS=	lib/ffmpeg7 share/doc/ffmpeg7

.include "../../mk/bsd.prefs.mk"

.if ${_USE_RPATH:tl} != "no"
CONFIGURE_ARGS+=	--enable-rpath
.endif

PRINT_PLIST_AWK+=	/html/ { $$0 = "$${PLIST.doc}" $$0 }
PRINT_PLIST_AWK+=	/css/ { $$0 = "$${PLIST.doc}" $$0 }

TEST_TARGET=	check

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt \
		${DESTDIR}${PREFIX}/share/doc/ffmpeg7

.include "options.mk"

# disable asm on i386 to avoid text relocations
.if ${MACHINE_ARCH} == "i386"
CONFIGURE_ARGS+=	--disable-asm
.endif

# configure script uses uname -m to detect arch, as opposed to uname -p in
# GNU/configure. Unable to detect NetBSD/macppc hosts correctly.
CONFIGURE_ARGS+=	--arch=${MACHINE_ARCH}

.include "../../multimedia/ffmpeg7/Makefile.common"
.include "../../mk/bsd.pkg.mk"
