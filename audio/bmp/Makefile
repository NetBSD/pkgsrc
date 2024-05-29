# $NetBSD: Makefile,v 1.97 2024/05/29 16:31:18 adam Exp $
#

DISTNAME=	bmp-0.9.7.1
PKGREVISION=	67
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=beepmp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://beepmp.sourceforge.net/
COMMENT=	Beep Media Player (fork of XMMS to work with GTK+ 2.x)
LICENSE=	gnu-gpl-v2

FILESDIR=		${.CURDIR}/../../audio/xmms/files
PATCH_SITES=		http://izb.knu.ac.kr/~bh/diffs/
PATCHFILES=		bmp-0.9.7-ipv6-simple.diff
PATCH_DIST_STRIP=	-p1

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config unzip:run

# XXX Workaround a crash during shutdown that happens when dlclose(3)ing
# any open plugin.  libstdc++ gets dynamically linked in when the id3lib
# library is loaded, and is the one causing problems.  See PR pkg/26846
# for more information.
USE_LANGUAGES=		c c++
LDFLAGS.NetBSD+=	-lstdc++ -lm

CONFIGURE_ARGS+=	--disable-alsa
CONFIGURE_ARGS+=	--disable-esd
CONFIGURE_ARGS+=	--disable-opengl
CONFIGURE_ARGS+=	--enable-mp3
CONFIGURE_ARGS+=	--enable-ogg
CONFIGURE_ARGS+=	--enable-vorbis

PKGCONFIG_OVERRIDE+=	bmp.pc

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=		cdaudio
.if ${OPSYS} != "Darwin"
PLIST.cdaudio=		yes
.endif
PRINT_PLIST_AWK+=	/cdaudio/ { print "$${PLIST.cdaudio}" $$0; next }

.if ${OPSYS} == "NetBSD"
.  include "../../mk/oss.buildlink3.mk"
RAWPART_cmd=		/sbin/sysctl -n kern.rawpartition | ${TR} 0-9 a-j
CONFIGURE_ARGS+=	--with-dev-dsp=${DEVOSSAUDIO:Q}			\
			--with-cdda-device=/dev/rcd0${RAWPART_cmd:sh}	\
			--with-cdda-dir=/cdrom/

post-extract:
	${RM} ${WRKSRC}/Output/OSS/soundcard.h
	${LN} -s /usr/include/soundcard.h ${WRKSRC}/Output/OSS/soundcard.h

.  if ${MACHINE_ARCH} == "i386"
post-patch:
.    if ${OBJECT_FMT} == "a.out"
	${CP} ${FILESDIR}/decode_i586_.s ${WRKSRC}/Input/mpg123/decode_i586.s
.    endif
	cd ${WRKSRC}/Input/mpg123 && \
	    ${MV} decode_i586.s decode_i586.s.orig && \
	    ${SED} -e 's@^/@#/@g' <decode_i586.s.orig >decode_i586.s
.  endif
.endif

.include "options.mk"
.include "../../audio/id3lib/buildlink3.mk"
.include "../../audio/libmikmod/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
