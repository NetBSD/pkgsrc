# $NetBSD: Makefile,v 1.9 2013/12/06 13:23:46 wiz Exp $

VER=		4.1.3.2
DISTNAME=	libreoffice-${VER}
PKGNAME=	libreoffice4-${VER}
PKGREVISION=	3
CATEGORIES=	misc
MASTER_SITES=	http://download.documentfoundation.org/libreoffice/src/4.1.3/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.libreoffice.org/
COMMENT=	Office productivity suite, 4.x branch
LICENSE=	gnu-lgpl-v3

# With -O2, when preference window is opened, soffice.bin crashes with SIGFPE.
.include "../../mk/bsd.prefs.mk"
.if !empty(MACHINE_PLATFORM:MNetBSD-5.*)
BUILDLINK_TRANSFORM+=	rename:-O2:-O
.endif

# LibreOfice's Makefile has its own pararell build mechanism. Avoid conflict.
MAKE_JOBS_SAFE=	no

CHECK_SHLIBS_SUPPORTED=	no

DIST_SUBDIR=	libreoffice

PYTHON_VERSIONS_ACCEPTED=	33

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
	0be45d54cc5e1c2e3102e32b8c190346-liberation-fonts-ttf-1.07.1.tar.gz \
	5c781723a0d9ed6188960defba8e91cf-liberation-fonts-ttf-2.00.1.tar.gz \
	1756c4fa6c616ae15973c104cd8cb256-Adobe-Core35_AFMs-314.tar.gz \
	1e9ddfe25ac9577da709d7b2ea36f939-source-sans-font-1.036.tar.gz \
	1f24ab1d39f4a51faf22244c94a6203f-xmlsec1-1.2.14.tar.gz \
	2a177023f9ea8ec8bd00837605c5df1b-jakarta-tomcat-5.0.30-src.tar.gz \
	625ff5f2f968dd908bca43c9469d6e6b-commons-lang-2.4-src.tar.gz \
	2c9b0f83ed5890af02c0df1c1776f39b-commons-httpclient-3.1-src.tar.gz \
	3404ab6b1792ae5f16bbd603bd1e1d03-libformula-1.1.7.zip \
	35c94d2df8893241173de1d16b6034c0-swingExSrc.zip \
	35efabc239af896dfb79be7ebdd6e6b9-gentiumbasic-fonts-1.10.zip \
	39bb3fcea1514f1369fcfc87542390fd-sacjava-1.3.zip \
	3bdf40c0d199af31923e900d082ca2dd-libfonts-1.1.6.zip \
	3c219630e4302863a9a83d0efde889db-commons-logging-1.1.1-src.tar.gz \
	46e92b68e31e858512b680b3b61dc4c1-mythes-1.2.3.tar.gz \
	36271d3fa0d9dec1632029b6d7aac925-liblangtag-0.5.1.tar.bz2 \
	798b2ffdc8bcfe7bca2cf92b62caf685-rhino1_5R5.zip \
	7a15edea7d415ac5150ea403e27401fd-open-sans-font-ttf-1.10.tar.gz \
	8ce2fcd72becf06c41f7201d15373ed9-librepository-1.1.6.zip \
	97b2d4dba862397f446b217e2b623e71-libloader-1.1.6.zip \
	b85436266b2ac91d351ab5684b181151-libwpg-0.2.2.tar.bz2 \
	a2f6010987e1c601274ab5d63b72c944-hyphen-2.8.4.tar.gz \
	a7983f859eafb2677d7ff386a023bc40-xsltml_2.1.2.zip \
	ace6ab49184e329db254e454a010f56d-libxml-1.1.7.zip \
	2e482c7567908d334785ce7d69ddfff7-commons-codec-1.6-src.tar.gz \
	ba2930200c9f019c2d93a8c88c651a0f-flow-engine-0.9.4.zip \
	b2371dc7cf4811c9d32146eec913d296-libcmis-0.3.0.tar.gz \
	c3c1a8ba7452950636e871d25020ce0d-pt-serif-font-1.0000W.tar.gz \
	46eb0e7f213ad61bd5dee0c494132cb0-libwps-0.2.9.tar.bz2 \
	db60e4fde8dd6d6807523deb71ee34dc-liblayout-0.2.10.zip \
	d8bd5eed178db6e2b18eeed243f85aa8-flute-1.1.6.zip \
	e7a384790b13c29113e22e596ade9687-LinLibertineG-20120116.zip \
	ea570af93c284aa9e5621cd563f54f4d-bsh-2.0b1-src.tar.gz \
	eeb2c7ddf0d302fba4bfc6e97eac9624-libbase-1.1.6.zip \
	f872f4ac066433d8ff92f5e316b36ff9-dejavu-fonts-ttf-2.33.zip \
	f94d9870737518e3b597f9265f4e9803-libserializer-1.1.6.zip \
	libcdr-0.0.14.tar.bz2 \
	libmspub-0.0.6.tar.bz2 \
	8473296c671b6e3dd8197f4145e0854b-libodfgen-0.0.2.tar.bz2 \
	b63e6340a02ff1cacfeadb2c42286161-JLanguageTool-1.7.0.tar.bz2 \
	05f84c95b610c21c5fd510d10debcabf-mariadb-native-client-1.0.0.tar.bz2 \
	08c85a6d6d793daee14e10e22eefdc4b-mdds_0.8.1.tar.bz2 \
	ea91f2fb4212a21d708aced277e6e85a-vigra1.4.0.tar.gz \
	185d60944ea767075d27247c3162b3bc-unowinreg.dll
#	libmwaw-0.1.10.tar.bz2
#	17410483b5b5f267aa18b7e00b65e6e0-hsqldb_1_8_0.zip
#	ac4781e01619be13461bb2d562b94a7b-cppunit-1.13.1.tar.gz
#	ea2acaf140ae40a87a952caa75184f4d-liborcus-0.5.1.tar.bz2
#	26b3e95ddf3d9c077c480ea45874b3b8-lp_solve_5.5.tar.gz
#	libvisio-0.0.28.tar.bz2
#	972afb8fdf02d9e7517e258b7fa7f0eb-libwpd-0.9.8.tar.bz2
#	ae330b9493bd4503ac390106ff6060d7-libexttextcat-3.4.3.tar.bz2

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

# dmake scripts use relative path with -rpath-link ld arguments, which
# is a no-go with normal pkgsrc wrappers.
# dmake is slowly beeing removed from the LibreOffice build process
# and this option will hopefully become unneeded in the future
WRAPPER_SKIP_TRANSFORM=yes

USE_LANGUAGES+=		c c++

USE_LIBTOOL=		yes
# GUN tar is really needed. Some Makefiles depends on GNUTAR.
USE_TOOLS+=		automake bash bison gmake gtar perl pkg-config unzip zip
PTHREAD_OPTS+=		require

HAS_CONFIGURE=		yes

# Do not use /tmp, outside of WRKSRC.
CONFIGURE_ENV+=		TMPDIR=${WRKSRC}/tmp

CONFIGURE_ARGS+=	--prefix=${DESTDIR}${PREFIX}/${PKGNAME_NOREV}
CONFIGURE_ARGS+=	--disable-ccache
CONFIGURE_ARGS+=	--disable-dbus
CONFIGURE_ARGS+=	--disable-epm
CONFIGURE_ARGS+=	--disable-fetch-external
CONFIGURE_ARGS+=	--disable-gconf
CONFIGURE_ARGS+=	--disable-gnome-vfs
CONFIGURE_ARGS+=	--disable-kde4
CONFIGURE_ARGS+=	--disable-lockdown
CONFIGURE_ARGS+=	--disable-odk
CONFIGURE_ARGS+=	--disable-opengl
CONFIGURE_ARGS+=	--disable-randr-link
CONFIGURE_ARGS+=	--disable-systray
# Enabling crashrep causes error. Non-official build does not need it.
CONFIGURE_ARGS+=	--disable-crashdump
CONFIGURE_ARGS+=	--enable-ext-presenter-minimizer
# Enabling GIO causes error. losessioninstall.component not found.
CONFIGURE_ARGS+=	--disable-gio
CONFIGURE_ARGS+=	--enable-gstreamer
CONFIGURE_ARGS+=	--enable-gtk3
CONFIGURE_ARGS+=	--enable-lockdown
CONFIGURE_ARGS+=	--enable-odk
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
CONFIGURE_ARGS+=	--with-parallelism=${MAKE_JOBS:Q}
CONFIGURE_ARGS+=	--with-system-clucene
CONFIGURE_ARGS+=	--with-system-libxml
CONFIGURE_ARGS+=	--with-system-boost
CONFIGURE_ARGS+=	--with-boost-libdir=${BUILDLINK_PREFIX.boost-libs}/lib
CONFIGURE_ARGS+=	--with-system-cairo
CONFIGURE_ARGS+=	--with-system-curl
CONFIGURE_ARGS+=	--with-system-dicts
CONFIGURE_ARGS+=	--with-system-expat
CONFIGURE_ARGS+=	--with-system-harfbuzz
CONFIGURE_ARGS+=	--with-system-hunspell
CONFIGURE_ARGS+=	--with-system-icu
CONFIGURE_ARGS+=	--with-system-jars
CONFIGURE_ARGS+=	--with-system-jpeg
CONFIGURE_ARGS+=	--with-system-lcms2
CONFIGURE_ARGS+=	--with-system-libexttextcat
CONFIGURE_ARGS+=	--with-system-libpng
CONFIGURE_ARGS+=	--with-system-libvisio
CONFIGURE_ARGS+=	--with-system-libwpd
CONFIGURE_ARGS+=	--with-system-libxml
CONFIGURE_ARGS+=	--with-system-lpsolve
CONFIGURE_ARGS+=	--with-system-mesa-headers
CONFIGURE_ARGS+=	--with-system-nss
CONFIGURE_ARGS+=	--with-system-openldap
CONFIGURE_ARGS+=	--with-system-openssl
CONFIGURE_ARGS+=	--with-system-libmwaw
CONFIGURE_ARGS+=	--with-system-orcus
CONFIGURE_ARGS+=	--with-system-poppler
CONFIGURE_ARGS+=	--with-system-postgresql
CONFIGURE_ARGS+=	--with-system-redland
CONFIGURE_ARGS+=	--with-system-neon
CONFIGURE_ARGS+=	--with-system-zlib
CONFIGURE_ARGS+=	--without-system-beanshell
# internal vigra should be used for effective developement.
CONFIGURE_ARGS+=	--without-system-vigra
CONFIGURE_ARGS+=	--with-vendor="pkgsrc"
CONFIGURE_ARGS+=	--without-doxygen
CONFIGURE_ARGS+=	--without-junit
CONFIGURE_ARGS+=	--without-krb5
CONFIGURE_ARGS+=	--without-gssapi
CONFIGURE_ARGS+=	--without-system-apache-commons
CONFIGURE_ARGS+=	--with-system-cppunit
CONFIGURE_ARGS+=	--without-system-jfreereport
# internal sane should be used for effective developement.
CONFIGURE_ARGS+=	--without-system-sane
CONFIGURE_ARGS+=	--without-system-servlet-api

# more REPLACE_PERL are needed.
REPLACE_PERL=	sd/res/webview/editpic.pl
REPLACE_PERL+=	sd/res/webview/poll.pl
REPLACE_PERL+=	sd/res/webview/savepic.pl
REPLACE_PERL+=	sd/res/webview/show.pl
REPLACE_PERL+=	sd/res/webview/webview.pl

LO_PROGRAMS=		sbase scalc sdraw simpress smath soffice swriter
# Base depends on java, we don't install the icon
LO_DESKTOP_FILES=	calc.desktop draw.desktop impress.desktop math.desktop \
			startcenter.desktop writer.desktop

CONFIGURE_SCRIPT=	./autogen.sh

MAKE_ENV+=		ROOT_USER=${ROOT_USER}
MAKE_ENV+=		ROOT_GROUP=${ROOT_GROUP}
BUILD_MAKE_FLAGS+=	VERBOSE=yes
BUILD_TARGET=		dev-install

BUILDLINK_TRANSFORM+=	rm:-ldl

INSTALLATION_DIRS=	bin share/applications

post-extract:
	${MKDIR} -p ${WRKSRC}/src
.for md in ${MORE_DISTFILES}
	${LN} -s ${DISTDIR}/${DIST_SUBDIR}/${md} ${WRKSRC}/src/${md}
.endfor
	mkdir ${WRKSRC}/tmp

do-install:
	cd ${WRKSRC} && make install

post-install:
.for f in ${LO_PROGRAMS}
	cd ${DESTDIR}${PREFIX}/bin && ${LN} -s ../${PKGNAME_NOREV}/program/${f}
.endfor
.for f in ${LO_DESKTOP_FILES}
	cd ${DESTDIR}${PREFIX}/share/applications && ${LN} -s ${DESTDIR}${PREFIX}/${PKGNAME_NOREV}/share/xdg/${f}
.endfor

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
.include "../../mk/pgsql.buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/cppunit/buildlink3.mk"
.include "../../devel/gperf/buildlink3.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../devel/nss/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2-xlib/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
#.include "../../graphics/sane-backends/buildlink3.mk"
#.include "../../graphics/vigra/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../math/lp_solve/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../print/cups/buildlink3.mk"
.include "../../print/poppler-cpp/buildlink3.mk"
.include "../../print/poppler-includes/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/hunspell/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/libclucene/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/redland/buildlink3.mk"
.include "../../textproc/libexttextcat/buildlink3.mk"
.include "../../textproc/mythes/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../www/neon/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
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
