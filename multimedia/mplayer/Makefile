# $NetBSD: Makefile,v 1.32 2006/10/11 00:01:00 grant Exp $

PKGNAME=	mplayer-${MPLAYER_PKG_VERSION}

COMMENT=	Software-only MPEG-1/2/4 video decoder

.include "../../multimedia/mplayer-share/Makefile.common"

PKGREVISION=	1

CONFIGURE_ARGS+=	--disable-mencoder
CONFIGURE_ARGS+=	--confdir=${PREFIX}/share/mplayer

# Solaris/x86 has Xv, but the header files live in /usr/X11R6, not
# ${X11_BASE}, so we need to also look for headers in this path.
.if ${OPSYS} == "SunOS" && ${MACHINE_ARCH} == "i386"
CPPFLAGS+=              	-I/usr/X11R6/include
BUILDLINK_PASSTHRU_DIRS+=	/usr/X11R6/include
.endif

INSTALLATION_DIRS+=	bin

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mplayer ${PREFIX}/bin

.include "../../multimedia/mplayer-share/Makefile.depends"

.include "../../mk/bsd.pkg.mk"

.include "../../multimedia/mplayer-share/Makefile.cflags"
