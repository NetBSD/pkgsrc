# $NetBSD: Makefile,v 1.100 2024/05/29 16:33:41 adam Exp $

PKGNAME=	${DISTNAME:S/ffmpeg/ffmpeg2/}
PKGREVISION=	19
MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ffmpeg.org/
COMMENT=	Decoding, encoding and streaming software (v2.x)

CONFIGURE_ARGS+=	--enable-avfilter
#CONFIGURE_ARGS+=	--enable-avfilter-lavf
CONFIGURE_ARGS+=	--enable-postproc
CONFIGURE_ARGS+=	--disable-ffplay

# Seems to cause internal compiler errors
CONFIGURE_ARGS+=	--disable-mmx
CONFIGURE_ARGS+=	--disable-mmxext

INSTALLATION_DIRS=	lib/ffmpeg2 share/doc/ffmpeg2 share/examples/ffmpeg2

CONF_FILES+=	${PREFIX}/share/examples/ffmpeg2/ffserver.conf \
		${PKG_SYSCONFDIR}/ffserver.conf

.include "../../mk/bsd.prefs.mk"

PRINT_PLIST_AWK+=	/html/ { $$0 = "$${PLIST.doc}" $$0 }
PRINT_PLIST_AWK+=	/opencl/ { $$0 = "$${PLIST.opencl}" $$0 }

TEST_TARGET=	check

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt \
		${DESTDIR}${PREFIX}/share/doc/ffmpeg2
	${INSTALL_DATA} ${WRKSRC}/doc/ffserver.conf \
		${DESTDIR}${PREFIX}/share/examples/ffmpeg2

.include "options.mk"

# disable asm on i386 to avoid text relocations
.if ${MACHINE_ARCH} == "i386"
CONFIGURE_ARGS+=	--disable-asm
.endif

.include "../../multimedia/ffmpeg2/Makefile.common"
