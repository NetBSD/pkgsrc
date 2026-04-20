# $NetBSD: Makefile,v 1.9 2026/04/20 18:14:10 adam Exp $

PKGNAME=	${DISTNAME:S/ffmpeg/ffmpeg8/}
PKGREVISION=	1
MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ffmpeg.org/
COMMENT=	Decoding, encoding and streaming software (v8.x)

CONFIGURE_ARGS+=	--enable-avfilter
CONFIGURE_ARGS+=	--disable-ffplay

INSTALLATION_DIRS=	lib/ffmpeg8 share/doc/ffmpeg8

.include "../../mk/bsd.prefs.mk"

.if ${_USE_RPATH:tl} != "no"
CONFIGURE_ARGS+=	--enable-rpath
.endif

PRINT_PLIST_AWK+=	/html/ { $$0 = "$${PLIST.doc}" $$0 }
PRINT_PLIST_AWK+=	/css/ { $$0 = "$${PLIST.doc}" $$0 }

TEST_TARGET=	check

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt \
		${DESTDIR}${PREFIX}/share/doc/ffmpeg8

.include "options.mk"

# disable asm on i386 to avoid text relocations
.if ${MACHINE_ARCH} == "i386"
CONFIGURE_ARGS+=	--disable-asm
.endif

# configure script uses uname -m to detect arch, as opposed to uname -p in
# GNU/configure. Unable to detect NetBSD/macppc hosts correctly.
CONFIGURE_ARGS+=	--arch=${MACHINE_ARCH}

.include "../../multimedia/ffmpeg8/Makefile.common"
.include "../../mk/bsd.pkg.mk"
