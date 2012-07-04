# $NetBSD: Makefile,v 1.7 2012/07/04 12:43:36 obache Exp $

VER=			3.5.4.2
DISTNAME=		libreoffice-${VER}
PKGNAME=		libreoffice-${VER:S/-//g}
PKGREVISION=		3
CATEGORIES=		misc
MASTER_SITES=	http://download.documentfoundation.org/libreoffice/src/3.5.4/ \
		http://www.numbertext.org/linux/

MAINTAINER=		ftigeot@wolfpond.org
HOMEPAGE=		http://www.libreoffice.org/
COMMENT=		Office productivity suite
LICENSE=		gnu-lgpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir
CHECK_SHLIBS_SUPPORTED=	no

DIST_SUBDIR=	libreoffice


LO_BOOTSTRAP=	libreoffice-core-${VER}
LO_COMPONENTS=	dictionaries help

MORE_DISTFILES= \
	1756c4fa6c616ae15973c104cd8cb256-Adobe-Core35_AFMs-314.tar.gz \
	e7a384790b13c29113e22e596ade9687-LinLibertineG-20120116.zip \
	f872f4ac066433d8ff92f5e316b36ff9-dejavu-fonts-ttf-2.33.zip \
	35efabc239af896dfb79be7ebdd6e6b9-gentiumbasic-fonts-1.10.zip \
	48a9f787f43a09c0a9b7b00cd1fddbbf-hyphen-2.7.1.tar.gz \
	7c2549f6b0a8bb604e6c4c729ffdcfe6-libcmis-0.1.0.tar.gz \
	0be45d54cc5e1c2e3102e32b8c190346-liberation-fonts-ttf-1.07.1.tar.gz \
	067201ea8b126597670b5eff72e1f66c-mythes-1.2.0.tar.gz \
	fdb27bfe2dbe2e7b57ae194d9bf36bab-SampleICC-1.3.2.tar.gz \
	1f24ab1d39f4a51faf22244c94a6203f-xmlsec1-1.2.14.tar.gz

DISTFILES=		${LO_BOOTSTRAP}.tar.xz
EXTRACT_ONLY=	${LO_BOOTSTRAP}.tar.xz
.for component in ${LO_COMPONENTS}
DISTFILES+=		libreoffice-${component}-${VER}.tar.xz
EXTRACT_ONLY+=	libreoffice-${component}-${VER}.tar.xz
.endfor

.for md in ${MORE_DISTFILES}
DISTFILES+=		${md}
SITES.${md}=		http://dev-www.libreoffice.org/src/
.endfor

.include "../../mk/bsd.prefs.mk"

# ftp: Unsupported URL scheme `https'
.if ${OPSYS} == "NetBSD"
FETCH_USING=		curl
.endif

# tar: Invalid header, starting valid header search.
EXTRACT_USING=		gtar

WRKSRC=		${WRKDIR}/${LO_BOOTSTRAP}

BUILD_DEPENDS+=		cppunit>1.12:../../devel/cppunit
BUILD_DEPENDS+=		gperf-[0-9]*:../../devel/gperf
BUILD_DEPENDS+=		hunspell>=1.2.8:../../textproc/hunspell
BUILD_DEPENDS+=		p5-Archive-Zip-[0-9]*:../../archivers/p5-Archive-Zip
BUILD_DEPENDS+=		zip-[0-9]*:../../archivers/zip

# dmake scripts use relative path with -rpath-link ld arguments, which
# is a no-go with normal pkgsrc wrappers.
# dmake is slowly beeing removed from the LibreOffice build process
# and this option will hopefully become unneeded in the future
WRAPPER_SKIP_TRANSFORM=yes

USE_LANGUAGES+=		c c++

CONFLICTS+=		staroffice-[0-9]*
CONFLICTS+=		openoffice-[0-9]*
CONFLICTS+=		openoffice2-[0-9]*
CONFLICTS+=		openoffice-bin-[0-9]*
CONFLICTS+=		openoffice2-bin-[0-9]*
CONFLICTS+=		openoffice3-[0-9]*
CONFLICTS+=		openoffice3-bin-[0-9]*
CONFLICTS+=		openoffice-linux-[0-9]*
CONFLICTS+=		libreoffice3-bin-[0-9]*

USE_TOOLS+=		automake bash bison gmake perl pkg-config unzip
PTHREAD_OPTS+=		require

HAS_CONFIGURE=		yes
CHECK_PORTABILITY_SKIP=	configure

CONFIGURE_ARGS+=	--prefix=${DESTDIR}${PREFIX}/${PKGNAME_NOREV}
CONFIGURE_ARGS+=	--disable-ccache
CONFIGURE_ARGS+=	--disable-epm
CONFIGURE_ARGS+=	--disable-ext-presenter-console
CONFIGURE_ARGS+=	--disable-gconf
CONFIGURE_ARGS+=	--disable-gnome-vfs
CONFIGURE_ARGS+=	--disable-mozilla
CONFIGURE_ARGS+=	--disable-neon
CONFIGURE_ARGS+=	--disable-odk
CONFIGURE_ARGS+=	--disable-opengl
CONFIGURE_ARGS+=	--disable-postgresql-sdbc
CONFIGURE_ARGS+=	--disable-strip-solver
CONFIGURE_ARGS+=	--disable-systray
CONFIGURE_ARGS+=	--with-alloc=system
CONFIGURE_ARGS+=	--with-fonts
CONFIGURE_ARGS+=	--with-num-cpus=${MAKE_JOBS}
CONFIGURE_ARGS+=	--with-system-headers
CONFIGURE_ARGS+=	--with-system-libs
CONFIGURE_ARGS+=	--with-vendor="The LibreOffice pkgsrc team"
CONFIGURE_ARGS+=	--without-java
CONFIGURE_ARGS+=	--without-system-altlinuxhyph
CONFIGURE_ARGS+=	--without-system-jars
CONFIGURE_ARGS+=	--without-system-libcmis
CONFIGURE_ARGS+=	--without-system-mozilla-headers
CONFIGURE_ARGS+=	--without-system-sampleicc

# Some LibreOffice build scripts do strange things with library paths
# and fail with the pkgsrc environment
# Preset LD_LIBRARY_PATH to sane defaults and avoid complicating them
# further
LIBPATH=	${BUILDLINK_DIR}/lib:${X11BASE}/lib
LIBPATH:=	${LIBPATH}:${WRKSRC}/desktop/unxdfly.pro/lib:${WRKSRC}/solver/unxdfly.pro/lib
LIBPATH:=	${LIBPATH}:${WRKSRC}/desktop/unxnbsd.pro/lib:${WRKSRC}/solver/unxnbsd.pro/lib

SUBST_CLASSES+=			libpath
SUBST_STAGE.libpath=	pre-configure
SUBST_FILES.libpath=	set_soenv.in
SUBST_SED.libpath=		-e 's,@LIBPATH@,${LIBPATH},g'
SUBST_MESSAGE.libpath=	Fixing library path for dmake scripts

SUBST_CLASSES+=			localbase
SUBST_STAGE.localbase=		pre-configure
SUBST_FILES.localbase=		configure.in
SUBST_SED.localbase=		-e 's,@LOCALBASE@,${PREFIX},'
SUBST_MESSAGE.localbase=	Fixing executable path for configure script

REPLACE_PERL=	sd/res/webview/editpic.pl
REPLACE_PERL+=	sd/res/webview/poll.pl
REPLACE_PERL+=	sd/res/webview/savepic.pl
REPLACE_PERL+=	sd/res/webview/show.pl
REPLACE_PERL+=	sd/res/webview/webview.pl

LO_PROGRAMS=		sbase scalc sdraw simpress smath soffice swriter
# Base depends on java, we don't install the icon
LO_DESKTOP_FILES=	calc.desktop draw.desktop impress.desktop math.desktop \
					printeradmin.desktop startcenter.desktop writer.desktop

post-extract:
	${MKDIR} -p ${WRKSRC}/clone
	${MKDIR} -p ${WRKSRC}/src
.for comp in ${LO_COMPONENTS}
	${MV} ${WRKDIR}/libreoffice-${comp}-${VER} ${WRKSRC}/clone/${comp}
.endfor
.for md in ${MORE_DISTFILES}
	${LN} -s ${DISTDIR}/${DIST_SUBDIR}/${md} ${WRKSRC}/src/${md}
.endfor

do-configure:
	cd ${WRKSRC} && ./autogen.sh ${CONFIGURE_ARGS}

post-configure:
	cd ${WRKSRC} && ./bin/create_bootstrap_links
	${TOUCH} ${WRKSRC}/src.downloaded

AUTO_MKDIRS=	yes
post-install:
	for f in ${LO_PROGRAMS}; do \
		${LN} -s ${DESTDIR}${PREFIX}/${PKGNAME_NOREV}/program/$$f ${DESTDIR}${PREFIX}/bin/$$f; \
	done
	${LN} -s ${DESTDIR}${PREFIX}/${PKGNAME_NOREV}/program/soffice ${DESTDIR}${PREFIX}/bin/libreoffice3.5
	for f in ${LO_DESKTOP_FILES}; do \
		${LN} -s ${DESTDIR}${PREFIX}/${PKGNAME_NOREV}/share/xdg/$$f ${DESTDIR}${PREFIX}/share/applications; \
	done


.include "../../converters/libvisio/buildlink3.mk"
.include "../../converters/libwpd/buildlink3.mk"
.include "../../converters/libwpg/buildlink3.mk"
.include "../../converters/libwps/buildlink3.mk"
.include "../../databases/db4/buildlink3.mk"
.include "../../databases/unixodbc/buildlink3.mk"
.include "../../devel/gperf/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/cppunit/buildlink3.mk"
.include "../../devel/mdds/buildlink3.mk"
.include "../../devel/nss/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2-xlib/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../graphics/sane-backends/buildlink3.mk"
.include "../../graphics/vigra/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../math/lp_solve/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../print/cups/buildlink3.mk"
.include "../../print/poppler-cpp/buildlink3.mk"
.include "../../print/poppler-includes/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/hunspell/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/redland/buildlink3.mk"
.include "../../textproc/libexttextcat/buildlink3.mk"
.include "../../textproc/mythes/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
