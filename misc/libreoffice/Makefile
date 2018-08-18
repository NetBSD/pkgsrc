# $NetBSD: Makefile,v 1.163 2018/08/18 00:11:32 ryoon Exp $

VERREL=		6.1.0
VERRC=		3
VER=		${VERREL}.${VERRC}
DISTNAME=	libreoffice-${VER}
CATEGORIES=	misc
MASTER_SITES=	http://download.documentfoundation.org/libreoffice/src/${VERREL}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://www.libreoffice.org/
COMMENT=	Office productivity suite from The Document Foundation
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	c gnu++11

SUBST_CLASSES+=			use-bash
SUBST_STAGE.use-bash=		pre-configure
SUBST_MESSAGE.use-bash=		Using bash for configure script
SUBST_FILES.use-bash+=		autogen.sh
SUBST_FILES.use-bash+=		configure.ac
SUBST_VARS.use-bash+=		BASH
SUBST_VARS.use-bash+=		PREFIX

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MNetBSD*)
pre-build:
	cd ${WRKSRC} && ${BUILD_MAKE_CMD} Executable_gengal && ${TOOLS_PLATFORM.paxctl} +m instdir/program/gengal.bin
.endif

GCC_REQD+=	4.6
PYTHON_VERSIONS_INCOMPATIBLE=	27 37

CHECK_SHLIBS_SUPPORTED=	no
# configure will be regenerated.
CHECK_PORTABILITY_SKIP=configure

NOT_PAX_MPROTECT_SAFE+=	${PKGNAME_NOREV}/lib/libreoffice/program/soffice.bin

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
	breakpad.zip \
	0168229624cfac409e766913506961a8-ucpp-1.3.2.tar.gz \
	134d8262145fc793c6af494dcace3e71-liberation-fonts-ttf-1.07.4.tar.gz \
	5c781723a0d9ed6188960defba8e91cf-liberation-fonts-ttf-2.00.1.tar.gz \
	907d6e99f241876695c19ff3db0b8923-source-code-pro-2.030R-ro-1.050R-it.tar.gz \
	xmlsec1-1.2.25.tar.gz \
	3404ab6b1792ae5f16bbd603bd1e1d03-libformula-1.1.7.zip \
	35c94d2df8893241173de1d16b6034c0-swingExSrc.zip \
	39bb3fcea1514f1369fcfc87542390fd-sacjava-1.3.zip \
	3bdf40c0d199af31923e900d082ca2dd-libfonts-1.1.6.zip \
	commons-logging-1.2-src.tar.gz \
	a8c2c5b8f09e7ede322d5c602ff6a4b6-mythes-1.2.4.tar.gz \
	8ce2fcd72becf06c41f7201d15373ed9-librepository-1.1.6.zip \
	97b2d4dba862397f446b217e2b623e71-libloader-1.1.6.zip \
	a7983f859eafb2677d7ff386a023bc40-xsltml_2.1.2.zip \
	ace6ab49184e329db254e454a010f56d-libxml-1.1.7.zip \
	ba2930200c9f019c2d93a8c88c651a0f-flow-engine-0.9.4.zip \
	db60e4fde8dd6d6807523deb71ee34dc-liblayout-0.2.10.zip \
	d8bd5eed178db6e2b18eeed243f85aa8-flute-1.1.6.zip \
	beeca87be45ec87d241ddd0e1bad80c1-bsh-2.0b6-src.zip \
	e7a384790b13c29113e22e596ade9687-LinLibertineG-20120116.zip \
	eeb2c7ddf0d302fba4bfc6e97eac9624-libbase-1.1.6.zip \
	33e1e61fab06a547851ed308b4ffef42-dejavu-fonts-ttf-2.37.zip \
	f94d9870737518e3b597f9265f4e9803-libserializer-1.1.6.zip \
	b63e6340a02ff1cacfeadb2c42286161-JLanguageTool-1.7.0.tar.bz2 \
	a233181e03d3c307668b4c722d881661-mariadb_client-2.0.0-src.tar.gz \
	798b2ffdc8bcfe7bca2cf92b62caf685-rhino1_5R5.zip \
	368f114c078f94214a308a74c7e991bc-crosextrafonts-20130214.tar.gz \
	language-subtag-registry-2017-12-14.tar.bz2 \
	libeot-0.01.tar.bz2 \
	7239a4430efd4d0189c4f24df67f08e5-mysql-connector-c++-1.1.4.tar.gz \
	c0b4799ea9850eae3ead14f0a60e9418-postgresql-9.2.1.tar.bz2 \
	edc4d741888bc0d38e32dbaa17149596-source-sans-pro-2.010R-ro-1.065R-it.tar.gz \
	graphite2-minimal-1.3.10.tgz \
	1725634df4bb3dcb1b2c91a6175f8789-GentiumBasic_1102.zip \
	EmojiOneColor-SVGinOT-1.3.tar.gz \
	libjpeg-turbo-1.5.2.tar.gz \
	alef-1.001.tar.gz \
	amiri-0.109.zip \
	c74b7223abe75949b4af367942d96c7a-crosextrafonts-carlito-20130920.tar.gz \
	culmus-0.131.tar.gz \
	ttf-kacst_2.01+mry.tar.gz \
	libre-hebrew-1.0.tar.gz \
	noto-fonts-20171024.tar.gz \
	Scheherazade-2.100.zip \
	lxml-4.1.1.tgz \
	Amiri-0.111.zip \
	ReemKufi-0.7.zip

MORE_DISTFILES+=		harfbuzz-1.8.7.tar.bz2

.for md in ${MORE_DISTFILES}
DISTFILES+=		${md}
SITES.${md}=		https://dev-www.libreoffice.org/src/
.endfor

SITES.harfbuzz-1.8.7.tar.bz2=	http://www.freedesktop.org/software/harfbuzz/release/

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

LDFLAGS+=		-lboost_system

USE_LIBTOOL=		yes
# Use GNU find from findutils.
TOOLS_PLATFORM.find=	# empty
# GUN tar is really needed. Some Makefiles depends on GNUTAR.
USE_TOOLS+=		automake bash bison gmake gtar
USE_TOOLS+=		msgfmt perl pkg-config unzip zip
PTHREAD_OPTS+=		require

HAS_CONFIGURE=		yes
#GNU_CONFIGURE=		yes

CXXFLAGS.NetBSD+=	-DNO_CPLUSPLUS_ALLOCA

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
CONFIGURE_ARGS+=	--disable-epm
CONFIGURE_ARGS+=	--disable-fetch-external
CONFIGURE_ARGS+=	--disable-firebird-sdbc
CONFIGURE_ARGS+=	--disable-odk
# Enabling GIO causes error. losessioninstall.component not found.
CONFIGURE_ARGS+=	--disable-gio
CONFIGURE_ARGS+=	--disable-pdfium
CONFIGURE_ARGS+=	--enable-gstreamer-1-0
CONFIGURE_ARGS+=	--enable-python=system
#CONFIGURE_ARGS+=	--enable-release-build
CONFIGURE_ARGS+=	--enable-ext-wiki-publisher
CONFIGURE_ARGS+=	--enable-ext-nlpsolver
CONFIGURE_ARGS+=	--enable-ext-mariadb-connector
CONFIGURE_ARGS+=	--with-system-gpgmepp
CONFIGURE_ARGS+=	--without-system-jpeg
CONFIGURE_ARGS+=	--without-system-mysql-cppconn
CONFIGURE_ARGS+=	--without-system-postgresql
CONFIGURE_ARGS+=	--without-system-mariadb
CONFIGURE_ARGS+=	--without-system-xmlsec
CONFIGURE_ARGS+=	--with-alloc=system
CONFIGURE_ARGS+=	--with-compat-oowrappers
CONFIGURE_ARGS+=	--with-external-tar=${WRKSRC}/src
CONFIGURE_ARGS+=	--with-fonts
CONFIGURE_ARGS+=	--with-lang="ALL"
CONFIGURE_ARGS+=	--with-myspell-dicts
CONFIGURE_ARGS+=	--with-boost-libdir=${BUILDLINK_PREFIX.boost-libs}/lib
CONFIGURE_ARGS+=	--with-system-libs
CONFIGURE_ARGS+=	--with-system-dicts
CONFIGURE_ARGS+=	--with-vendor="pkgsrc"
CONFIGURE_ARGS+=	--without-doxygen
CONFIGURE_ARGS+=	--without-junit
CONFIGURE_ARGS+=	--without-krb5
CONFIGURE_ARGS+=	--without-gssapi
CONFIGURE_ARGS+=	--without-system-apache-commons
CONFIGURE_ARGS+=	--with-system-cppunit
# gengal.bin segfault, in runtime same problem causes application error.
#CONFIGURE_ARGS+=	--without-galleries
# internal sane should be used because only header files are used.
CONFIGURE_ARGS+=	--without-system-sane
# Use internal harfbuzz because fonts/harfbuzz has no graphite2 support.
CONFIGURE_ARGS+=	--without-system-harfbuzz
CONFIGURE_ARGS+=	--without-system-graphite
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

pre-configure: provide-python3

.PHONY: provide-python3
provide-python3:
	# install phase uses python3 command
	${LN} -s ${PYTHONBIN} "${BUILDLINK_DIR}/bin/python3"

do-install:
	cd ${WRKSRC} && make DESTDIR="${DESTDIR}" PREFIXDIR="${PREFIX}" distro-pack-install
# make install cleans ${DESTDIR}${PREFIX}/*, so bin etc. are removed.
.for d in ${INSTALLATION_DIRS}
	cd ${DESTDIR}${PREFIX} && \
		${MKDIR} ${d}
.endfor

UNO_PATH=${PREFIX}/${PKGNAME}/lib/libreoffice/program

BUILD_DEFS+=   UNO_PATH
BUILD_DEFS+=   PYTHONBIN

#post-install:
#.for f in ${LO_PROGRAMS}
#	cd ${DESTDIR}${PREFIX}/bin && ${LN} -s ../${PKGNAME_NOREV}/program/${f}
#.endfor
#	${LN} -s ${DESTDIR}${PREFIX}/bin/soffice ${DESTDIR}${PREFIX}/bin/libreoffice
#.for f in ${LO_DESKTOP_FILES}
#	cd ${DESTDIR}${PREFIX}/share/applications && ${LN} -s ${DESTDIR}${PREFIX}/${PKGNAME_NOREV}/share/xdg/${f}
#.endfor

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../converters/libabw/buildlink3.mk"
.include "../../converters/libcdr/buildlink3.mk"
.include "../../converters/libe-book/buildlink3.mk"
.include "../../converters/libepubgen/buildlink3.mk"
BUILDLINK_API_DEPENDS.libetonyek+=	libetonyek>=0.1.2
.include "../../converters/libetonyek/buildlink3.mk"
.include "../../converters/libfreehand/buildlink3.mk"
.include "../../converters/librevenge/buildlink3.mk"
.include "../../converters/libmspub/buildlink3.mk"
.include "../../converters/libpagemaker/buildlink3.mk"
.include "../../converters/libqxp/buildlink3.mk"
.include "../../converters/libstaroffice/buildlink3.mk"
.include "../../converters/libvisio/buildlink3.mk"
.include "../../converters/libwpd/buildlink3.mk"
.include "../../converters/libwpg/buildlink3.mk"
.include "../../converters/libwps/buildlink3.mk"
.include "../../converters/libmwaw/buildlink3.mk"
.include "../../converters/libzmf/buildlink3.mk"
.include "../../converters/orcus/buildlink3.mk"
.include "../../databases/db4/buildlink3.mk"
.include "../../databases/openldap-client/buildlink3.mk"
.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../databases/unixodbc/buildlink3.mk"
.include "../../devel/apr-util/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/cppunit/buildlink3.mk"
.include "../../devel/gperf/buildlink3.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../devel/liblangtag/buildlink3.mk"
.include "../../devel/mdds1.2/buildlink3.mk"
.include "../../devel/nss/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
# hardbuzz with graphite2 support is required.
#BUILDLINK_API_DEPENDS.harfbuzz+=	harfbuzz>=1.4.2
#.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../graphics/graphite2/buildlink3.mk"
# Requires JCS_EXT_BGRA
#.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2-xlib/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/glm/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/libepoxy/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
#.include "../../graphics/sane-backends/buildlink3.mk"
#.include "../../graphics/vigra/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/tool.mk"
.include "../../math/coinmp/buildlink3.mk"
.include "../../math/libnumbertext/buildlink3.mk"
.include "../../math/lp_solve/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../net/libcmis/buildlink3.mk"
.include "../../net/mDNSResponder/buildlink3.mk"
.if !empty(PKG_OPTIONS:Mcups)
.include "../../print/cups-base/buildlink3.mk"
.endif
.include "../../print/poppler-cpp/buildlink3.mk"
.include "../../print/poppler-includes/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
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
.include "../../textproc/raptor2/buildlink3.mk"
.include "../../textproc/rasqal/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../www/neon/buildlink3.mk"
.include "../../www/serf/buildlink3.mk"
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
.include "../../x11/pixman/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
