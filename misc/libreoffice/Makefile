# $NetBSD: Makefile,v 1.73 2016/02/13 08:46:02 wiz Exp $

VERREL=		5.1.0
VERRC=		3
VER=		${VERREL}.${VERRC}
DISTNAME=	libreoffice-${VER}
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://download.documentfoundation.org/libreoffice/src/${VERREL}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.libreoffice.org/
COMMENT=	Office productivity suite from The Document Foundation
LICENSE=	gnu-lgpl-v3

# With -O2, when preference window is opened, soffice.bin crashes with SIGFPE.
.include "../../mk/bsd.prefs.mk"
.if !empty(MACHINE_PLATFORM:MNetBSD-5.*)
BUILDLINK_TRANSFORM+=	opt:-O2:-O
.endif

GCC_REQD+=	4.6
PYTHON_VERSIONS_INCOMPATIBLE=	27

CHECK_SHLIBS_SUPPORTED=	no
# configure will be regenerated.
CHECK_PORTABILITY_SKIP=configure

DIST_SUBDIR=	libreoffice

LO_BOOTSTRAP=	${DISTNAME}
LO_COMPONENTS=	dictionaries help translations

DISTFILES+=	${LO_BOOTSTRAP}${EXTRACT_SUFX}
EXTRACT_ONLY=	${LO_BOOTSTRAP}${EXTRACT_SUFX}

.for component in ${LO_COMPONENTS}
DISTFILES+=		libreoffice-${component}-${VER}.tar.xz
EXTRACT_ONLY+=		libreoffice-${component}-${VER}.tar.xz
.endfor

MORE_DISTFILES= \
	0168229624cfac409e766913506961a8-ucpp-1.3.2.tar.gz \
	0279a21fab6f245e85a6f85fea54f511-source-code-font-1.009.tar.gz \
	134d8262145fc793c6af494dcace3e71-liberation-fonts-ttf-1.07.4.tar.gz \
	5c781723a0d9ed6188960defba8e91cf-liberation-fonts-ttf-2.00.1.tar.gz \
	edc4d741888bc0d38e32dbaa17149596-source-sans-pro-2.010R-ro-1.065R-it.tar.gz \
	1f24ab1d39f4a51faf22244c94a6203f-xmlsec1-1.2.14.tar.gz \
	8ab049135b2d15313da5d9f0656894a1-commons-lang3-3.3.1-src.tar.gz \
	2c9b0f83ed5890af02c0df1c1776f39b-commons-httpclient-3.1-src.tar.gz \
	3404ab6b1792ae5f16bbd603bd1e1d03-libformula-1.1.7.zip \
	35c94d2df8893241173de1d16b6034c0-swingExSrc.zip \
	35efabc239af896dfb79be7ebdd6e6b9-gentiumbasic-fonts-1.10.zip \
	39bb3fcea1514f1369fcfc87542390fd-sacjava-1.3.zip \
	3bdf40c0d199af31923e900d082ca2dd-libfonts-1.1.6.zip \
	commons-logging-1.2-src.tar.gz \
	a8c2c5b8f09e7ede322d5c602ff6a4b6-mythes-1.2.4.tar.gz \
	7a15edea7d415ac5150ea403e27401fd-open-sans-font-ttf-1.10.tar.gz \
	8ce2fcd72becf06c41f7201d15373ed9-librepository-1.1.6.zip \
	97b2d4dba862397f446b217e2b623e71-libloader-1.1.6.zip \
	a7983f859eafb2677d7ff386a023bc40-xsltml_2.1.2.zip \
	ace6ab49184e329db254e454a010f56d-libxml-1.1.7.zip \
	048751f3271906db5126ab76870444c4-commons-codec-1.9-src.zip \
	ba2930200c9f019c2d93a8c88c651a0f-flow-engine-0.9.4.zip \
	c3c1a8ba7452950636e871d25020ce0d-pt-serif-font-1.0000W.tar.gz \
	db60e4fde8dd6d6807523deb71ee34dc-liblayout-0.2.10.zip \
	d8bd5eed178db6e2b18eeed243f85aa8-flute-1.1.6.zip \
	e7a384790b13c29113e22e596ade9687-LinLibertineG-20120116.zip \
	ec1941a74d3ef513c4ce57a9092b74e1-bsh-2.0b5-src.zip \
	eeb2c7ddf0d302fba4bfc6e97eac9624-libbase-1.1.6.zip \
	d8b5214d35bcd2bfcb2cffa7795b351d-dejavu-fonts-ttf-2.35.zip \
	f94d9870737518e3b597f9265f4e9803-libserializer-1.1.6.zip \
	b63e6340a02ff1cacfeadb2c42286161-JLanguageTool-1.7.0.tar.bz2 \
	a233181e03d3c307668b4c722d881661-mariadb_client-2.0.0-src.tar.gz \
	d62650a6f908e85643e557a236ea989c-vigra1.6.0.tar.gz \
	185d60944ea767075d27247c3162b3bc-unowinreg.dll \
	c74b7223abe75949b4af367942d96c7a-crosextrafonts-carlito-20130920.tar.gz \
	OpenCOLLADA-master-6509aa13af.tar.bz2 \
	798b2ffdc8bcfe7bca2cf92b62caf685-rhino1_5R5.zip \
	368f114c078f94214a308a74c7e991bc-crosextrafonts-20130214.tar.gz

.for md in ${MORE_DISTFILES}
DISTFILES+=		${md}
SITES.${md}=		http://dev-www.libreoffice.org/src/
.endfor

DISTFILES+=e7a384790b13c29113e22e596ade9687-LinLibertineG-20120116.zip
SITES.e7a384790b13c29113e22e596ade9687-LinLibertineG-20120116.zip=http://www.numbertext.org/linux/

DISTFILES+=185d60944ea767075d27247c3162b3bc-unowinreg.dll
SITES.185d60944ea767075d27247c3162b3bc-unowinreg.dll=http://download.go-oo.org/extern/

.include "options.mk"

.include "../../mk/bsd.prefs.mk"

# tar: Invalid header, starting valid header search.
EXTRACT_USING=		gtar

WRKSRC=		${WRKDIR}/${LO_BOOTSTRAP}

BUILD_DEPENDS+=		p5-Archive-Zip-[0-9]*:../../archivers/p5-Archive-Zip
DEPENDS+=		${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

# dmake scripts use relative path with -rpath-link ld arguments, which
# is a no-go with normal pkgsrc wrappers.
# dmake is slowly beeing removed from the LibreOffice build process
# and this option will hopefully become unneeded in the future
WRAPPER_SKIP_TRANSFORM=yes

USE_LANGUAGES+=		c c++

LDFLAGS+=		-lboost_system

USE_LIBTOOL=		yes
# Use GNU find fron findutils.
TOOLS_PLATFORM.find=	# empty
# GUN tar is really needed. Some Makefiles depends on GNUTAR.
USE_TOOLS+=		automake bash bison gmake gtar perl pkg-config unzip zip
PTHREAD_OPTS+=		require

HAS_CONFIGURE=		yes
#GNU_CONFIGURE=		yes

# Do not use /tmp, outside of WRKSRC.
CONFIGURE_ENV+=		TMPDIR=${WRKSRC}/tmp
CONFIGURE_ENV+=		ANT_LIB=${LOCALBASE}/lib/java/ant

MAKE_JOBS_SAFE=		no # --with-parallelism conficts with -jN
.if !empty(MAKE_JOBS)
CONFIGURE_ARGS+=	--with-parallelism=${MAKE_JOBS}
.else
CONFIGURE_ARGS+=	--with-parallelism=1
.endif


CONFIGURE_ARGS+=	--prefix=${PREFIX}/${PKGNAME_NOREV}
CONFIGURE_ARGS+=	--disable-ccache
CONFIGURE_ARGS+=	--enable-dbus
# We cannot use system collada2gltf, and NetBSD requires some patches (4.3.2.2)
CONFIGURE_ARGS+=	--disable-collada
CONFIGURE_ARGS+=	--disable-epm
CONFIGURE_ARGS+=	--disable-fetch-external
CONFIGURE_ARGS+=	--disable-firebird-sdbc
CONFIGURE_ARGS+=	--disable-odk
CONFIGURE_ARGS+=	--disable-randr-link
CONFIGURE_ARGS+=	--disable-systray
# Enabling crashrep causes error. Non-official build does not need it.
CONFIGURE_ARGS+=	--disable-crashdump
# Enabling GIO causes error. losessioninstall.component not found.
CONFIGURE_ARGS+=	--disable-gio
CONFIGURE_ARGS+=	--enable-gstreamer-1-0
CONFIGURE_ARGS+=	--enable-python=system
#CONFIGURE_ARGS+=	--enable-release-build
CONFIGURE_ARGS+=	--enable-ext-wiki-publisher
CONFIGURE_ARGS+=	--enable-ext-nlpsolver
CONFIGURE_ARGS+=	--with-alloc=system
CONFIGURE_ARGS+=	--with-compat-oowrappers
CONFIGURE_ARGS+=	--with-external-tar=${DISTDIR}/${DIST_SUBDIR}
CONFIGURE_ARGS+=	--with-fonts
CONFIGURE_ARGS+=	--with-lang="ALL"
CONFIGURE_ARGS+=	--with-myspell-dicts
CONFIGURE_ARGS+=	--with-boost-libdir=${BUILDLINK_PREFIX.boost-libs}/lib
CONFIGURE_ARGS+=	--with-system-libs
CONFIGURE_ARGS+=	--with-system-dicts
# internal vigra should be used because only header files are used.
CONFIGURE_ARGS+=	--without-system-vigra
CONFIGURE_ARGS+=	--with-vendor="pkgsrc"
CONFIGURE_ARGS+=	--without-doxygen
CONFIGURE_ARGS+=	--without-junit
CONFIGURE_ARGS+=	--without-krb5
CONFIGURE_ARGS+=	--without-gssapi
CONFIGURE_ARGS+=	--without-system-apache-commons
CONFIGURE_ARGS+=	--with-system-cppunit
CONFIGURE_ARGS+=	--with-system-libgltf
CONFIGURE_ARGS+=	--without-system-npapi-headers
# internal sane should be used because only header files are used.
CONFIGURE_ARGS+=	--without-system-sane
# sbin might not be in PATH
CONFIGURE_ARGS+=	ac_cv_path_SYSTEM_GENCCODE=${BUILDLINK_PREFIX.icu}/sbin/genccode
CONFIGURE_ARGS+=	ac_cv_path_SYSTEM_GENCMN=${BUILDLINK_PREFIX.icu}/sbin/gencmn

# more REPLACE_PERL are needed.
REPLACE_PERL=	sd/res/webview/editpic.pl
REPLACE_PERL+=	sd/res/webview/poll.pl
REPLACE_PERL+=	sd/res/webview/savepic.pl
REPLACE_PERL+=	sd/res/webview/show.pl
REPLACE_PERL+=	sd/res/webview/webcast.pl

LO_PROGRAMS=		sbase scalc sdraw simpress smath soffice swriter
# Base depends on java, we don't install the icon
LO_DESKTOP_FILES=	calc.desktop draw.desktop impress.desktop math.desktop \
			startcenter.desktop writer.desktop

#OBJDIR=			pkgsrcbuild
#CONFIGURE_DIRS=		${OBJDIR}
CONFIGURE_SCRIPT=	${WRKSRC}/autogen.sh

#LD_LIBRARY_PATH+=	${WRKSRC}/instdir/sdk/lib:${WRKSRC}/instdir/ure/lib:${WRKSRC}/instdir/program

MAKE_ENV+=		ROOT_USER=${ROOT_USER}
MAKE_ENV+=		ROOT_GROUP=${ROOT_GROUP}
MAKE_ENV+=		SHELL=${BASH}
#MAKE_ENV+=		LD_LIBRARY_PATH=${LD_LIBRARY_PATH}
BUILD_MAKE_FLAGS+=	VERBOSE=true
#BUILD_MAKE_FLAGS+=	GMAKE_OPTIONS+=-p

BUILDLINK_TRANSFORM+=	rm:-ldl

INSTALLATION_DIRS=	bin share/applications

.PHONY: debugrun
# For debugging
debugrun:
	cd ${WRKSRC} && gmake debugrun

post-extract:
	${MKDIR} -p ${WRKSRC}/src
.for md in ${MORE_DISTFILES}
	${LN} -s ${DISTDIR}/${DIST_SUBDIR}/${md} ${WRKSRC}/src/${md}
.endfor
	mkdir ${WRKSRC}/tmp
#	mkdir ${WRKSRC}/${OBJDIR}

do-install:
	cd ${WRKSRC} && make DESTDIR="${DESTDIR}" PREFIXDIR="${PREFIX}" distro-pack-install
# make install cleans ${DESTDIR}${PREFIX}/*, so bin etc. are removed.
.for d in ${INSTALLATION_DIRS}
	cd ${DESTDIR}${PREFIX} && \
		${MKDIR} ${d}
.endfor

#post-install:
#.for f in ${LO_PROGRAMS}
#	cd ${DESTDIR}${PREFIX}/bin && ${LN} -s ../${PKGNAME_NOREV}/program/${f}
#.endfor
#	${LN} -s ${DESTDIR}${PREFIX}/bin/soffice ${DESTDIR}${PREFIX}/bin/libreoffice
#.for f in ${LO_DESKTOP_FILES}
#	cd ${DESTDIR}${PREFIX}/share/applications && ${LN} -s ${DESTDIR}${PREFIX}/${PKGNAME_NOREV}/share/xdg/${f}
#.endfor

.include "../../converters/libabw/buildlink3.mk"
.include "../../converters/libcdr/buildlink3.mk"
.include "../../converters/libe-book/buildlink3.mk"
BUILDLINK_API_DEPENDS.libetonyek+=	libetonyek>=0.1.2
.include "../../converters/libetonyek/buildlink3.mk"
.include "../../converters/libfreehand/buildlink3.mk"
.include "../../converters/librevenge/buildlink3.mk"
.include "../../converters/libmspub/buildlink3.mk"
.include "../../converters/libpagemaker/buildlink3.mk"
.include "../../converters/libvisio/buildlink3.mk"
.include "../../converters/libwpd/buildlink3.mk"
.include "../../converters/libwpg/buildlink3.mk"
.include "../../converters/libwps/buildlink3.mk"
.include "../../converters/libmwaw/buildlink3.mk"
.include "../../converters/orcus/buildlink3.mk"
.include "../../databases/db4/buildlink3.mk"
.include "../../databases/openldap-client/buildlink3.mk"
.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../databases/unixodbc/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/cppunit/buildlink3.mk"
.include "../../devel/gperf/buildlink3.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../devel/liblangtag/buildlink3.mk"
.include "../../devel/mdds/buildlink3.mk"
.include "../../devel/nss/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2-xlib/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/glm/buildlink3.mk"
.include "../../graphics/graphite2/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/libgltf/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
#.include "../../graphics/sane-backends/buildlink3.mk"
#.include "../../graphics/vigra/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/tool.mk"
.include "../../math/coinmp/buildlink3.mk"
.include "../../math/lp_solve/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../net/libcmis/buildlink3.mk"
.include "../../print/cups/buildlink3.mk"
.include "../../print/poppler-cpp/buildlink3.mk"
.include "../../print/poppler-includes/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/hunspell/buildlink3.mk"
.include "../../textproc/hyphen/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/libclucene/buildlink3.mk"
BUILDLINK_API_DEPENDS.libodfgen+=       libodfgen>=0.1.4
.include "../../textproc/libodfgen/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/redland/buildlink3.mk"
.include "../../textproc/libexttextcat/buildlink3.mk"
.include "../../textproc/mythes/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../www/neon/buildlink3.mk"
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
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
