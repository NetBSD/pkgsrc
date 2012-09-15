# $NetBSD: Makefile,v 1.73 2012/09/15 10:05:42 obache Exp $

OO_VER=			3.1.1
OO_TAG=			OOO310_m19
DISTNAME=		openoffice-${OO_VER}
PKGNAME=		openoffice3-${OO_VER}
PKGREVISION=		30
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_OPENOFFICE:=stable/${OO_VER}/}
DIST_SUBDIR=		${DISTNAME}

DISTFILES=		OOo_${OO_VER}_src_core.tar.bz2
DISTFILES+=		OOo_${OO_VER}_src_binfilter.tar.bz2
DISTFILES+=		OOo_${OO_VER}_src_l10n.tar.bz2
DISTFILES+=		OOo_${OO_VER}_src_system.tar.bz2
DISTFILES+=		OOo_${OO_VER}_src_extensions.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.openoffice.org/
COMMENT=		Integrated office productivity suite (version 3)
LICENSE=		gnu-lgpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+=		p5-Archive-Zip-[0-9]*:../../archivers/p5-Archive-Zip

DEPENDS+=		libpaper-[0-9]*:../../print/libpaper

.include "../../mk/bsd.prefs.mk"

WRKSRC=			${WRKDIR}/${OO_TAG}

# Cannot compile with 3.3.x (GCC Bugzilla Bug 16879).
GCC_REQD+=		3.4
USE_LANGUAGES+=		c c++

CONFLICTS+=		staroffice-[0-9]*
CONFLICTS+=		openoffice-[0-9]*
CONFLICTS+=		openoffice2-[0-9]*
CONFLICTS+=		openoffice-bin-[0-9]*
CONFLICTS+=		openoffice2-bin-[0-9]*
CONFLICTS+=		openoffice3-bin-[0-9]*
CONFLICTS+=		openoffice-linux-[0-9]*

USE_TOOLS+=		bash bison gmake imake perl pkg-config tar unzip zip
PTHREAD_OPTS+=		require
PTHREAD_AUTO_VARS=	yes

ONLY_FOR_PLATFORM=	FreeBSD-*-i386 FreeBSD-*-x86_64
ONLY_FOR_PLATFORM+=	NetBSD-1.6Z[G-Z]*-i386 NetBSD-[2-9]*-i386
ONLY_FOR_PLATFORM+=	NetBSD-1.6Z[G-Z]*-x86_64 NetBSD-[2-9]*-x86_64

GNU_CONFIGURE=		yes

REPLACE_PERL+=		sd/res/webview/editpic.pl	\
			sd/res/webview/poll.pl		\
			sd/res/webview/savepic.pl	\
			sd/res/webview/show.pl		\
			sd/res/webview/webview.pl
REPLACE_PYTHON+=	scripting/source/pyprov/mailmerge.py

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-patch
SUBST_MESSAGE.prefix=	Fixing prefix
SUBST_FILES.prefix=	sysui/desktop/share/openoffice.sh
SUBST_FILES.prefix+=	sysui/desktop/share/printeradmin.sh
SUBST_SED.prefix=	-e 's|@OO_PREFIX@|${OO_PREFIX}|g'

SUBST_CLASSES+=		lib
SUBST_STAGE.lib=	post-patch
SUBST_MESSAGE.lib=	Adding library paths
SUBST_FILES.lib=	solenv/inc/pkgsrc.mk
SUBST_SED.lib+=		-e 's|@COMPILER_RPATH_FLAG@|${COMPILER_RPATH_FLAG}|g'
SUBST_SED.lib+=		-e 's|@OO_LIBDIR@|${OO_PREFIX}/${OO_UNXNAME}/basis-link/program|g'
.for pkg in db4 expat icu jpeg zlib
LIB.${pkg}=		-L${BUILDLINK_PREFIX.${pkg}}/lib
LIB.${pkg}+=		${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.${pkg}}/lib
SUBST_SED.lib+=		-e 's|@LIB_${pkg}@|${LIB.${pkg}}|g'
LIBS+=			${LIB.${pkg}}
.endfor

CONFIGURE_ENV+=		LIBS=${LIBS:O:u:Q}
CONFIGURE_ENV+=		X_LIBS=${X11_LDFLAGS:M*:Q}
CONFIGURE_ENV+=		BLNK_PREFIX_db4=${BUILDLINK_PREFIX.db4}
CONFIGURE_ENV+=		ac_cv_path_SYSTEM_GENBRK=${PREFIX}/bin/genbrk
CONFIGURE_ENV+=		ac_cv_path_SYSTEM_GENCCODE=${PREFIX}/sbin/genccode
CONFIGURE_ENV+=		ac_cv_path_SYSTEM_GENCMN=${PREFIX}/sbin/gencmn
CONFIGURE_ENV+=		USE_BUILTIN_openssl=${USE_BUILTIN.openssl}

CONFIGURE_ARGS+=	--with-use-shell=bash
CONFIGURE_ARGS+=	--enable-binfilter
CONFIGURE_ARGS+=	--enable-cairo
CONFIGURE_ARGS+=	--disable-systray
CONFIGURE_ARGS+=	--disable-ldap
CONFIGURE_ARGS+=	--disable-odk
CONFIGURE_ARGS+=	--disable-gcjaot
CONFIGURE_ARGS+=	--with-system-stdlibs
CONFIGURE_ARGS+=	--with-system-cairo
CONFIGURE_ARGS+=	--with-system-curl
CONFIGURE_ARGS+=	--with-system-db
CONFIGURE_ARGS+=	--with-system-expat
CONFIGURE_ARGS+=	--with-system-freetype
CONFIGURE_ARGS+=	--with-system-hunspell
CONFIGURE_ARGS+=	--with-system-icu
CONFIGURE_ARGS+=	--with-system-jpeg
CONFIGURE_ARGS+=	--with-system-libxml
CONFIGURE_ARGS+=	--with-system-libxslt
CONFIGURE_ARGS+=	--with-system-neon
CONFIGURE_ARGS+=	--with-system-openssl
CONFIGURE_ARGS+=	--with-system-python
CONFIGURE_ARGS+=	--with-system-zlib
CONFIGURE_ARGS+=	--with-dynamic-xinerama

# Extensions
CONFIGURE_ARGS+=	--enable-minimizer
CONFIGURE_ARGS+=	--enable-presenter-console
CONFIGURE_ARGS+=	--enable-pdfimport
OO_EXTENSIONS+=		minimizer/sun-presentation-minimizer.oxt
OO_EXTENSIONS+=		pdfimport/pdfimport.oxt
OO_EXTENSIONS+=		presenter/presenter-screen.oxt

# `portable' supports all platforms.
CONFIGURE_ARGS+=	--enable-epm --with-package-format=portable

# Language option.
CONFIGURE_ARGS+=	--with-lang=${OO_LANGS:Q}

.include "options.mk"

UNLIMIT_RESOURCES+=	datasize

OO_RELEASE=		OpenOffice.org${OO_VER}
PLIST_SRC+=		${PKGDIR}/PLIST
PLIST_SRC+=		${WRKDIR}/PLIST
PLIST_SUBST+=		OO_UNXNAME=${OO_UNXNAME}
PLIST_SUBST+=		OO_ICON_PREFIX=openofficeorg3
MESSAGE_SUBST+=		OO_PREFIX=${OO_PREFIX}
INSTALLATION_DIRS=	bin lib/${OO_RELEASE} share/applications	\
			lib/${OO_RELEASE}/extensions			\
			share/application-registry share/mime-info	\
			share/mime/packages

OO_UNXNAME=	openoffice.org3
OO_PKGPATH=	${WRKSRC}/instsetoo_native/${OPENOFFICE_OUTPATH}.pro/OpenOffice/portable/install
OO_LANGPACKPATH=${WRKSRC}/instsetoo_native/${OPENOFFICE_OUTPATH}.pro/OpenOffice_languagepack/portable/install
OO_PROGRAMS=	scalc sdraw simpress soffice swriter unopkg
OO_PREFIX=	${PREFIX}/lib/${OO_RELEASE}

post-extract:
	cd ${WRKSRC}/bridges/source/cpp_uno &&			\
	mv gcc3_netbsd_intel gcc3_netbsd_intel.orig &&		\
	cp -Rp gcc3_freebsd_intel gcc3_netbsd_intel &&		\
	cp -Rp gcc3_freebsd_x86-64 gcc3_netbsd_x86-64

do-build:
	@${_ULIMIT_CMD} ${SETENV} ${MAKE_ENV} bash -c	\
	"cd ${WRKSRC} && ./bootstrap && source ${OPENOFFICE_SETFILE}Env.Set.sh && cd instsetoo_native && build.pl --checkmodules && build.pl -P${MAKE_JOBS:U1} --all product=full && cd util && dmake openoffice_${OO_BASELANG} && dmake ooolanguagepack"

do-install:
	cd ${DESTDIR}${OO_PREFIX} &&				\
	for f in ${OO_PKGPATH:Q}/${OO_BASELANG}/*/*.sw; do	\
		tar xpf $$f;					\
	done;							\
	for lang in ${OO_LANGPACKS}; do				\
		for f in ${OO_LANGPACKPATH:Q}/$$lang/*/*.sw; do	\
			tar xpf $$f;				\
		done;						\
	done
	cd ${DESTDIR}${OO_PREFIX}/${OO_UNXNAME}/basis-link/program &&	\
	chmod ${SHAREMODE} gengalrc hid.lst testtoolrc
	for f in ${OO_PROGRAMS}; do					\
		ln -sf ${DESTDIR}${OO_PREFIX}/${OO_UNXNAME}/program/$$f	\
			${DESTDIR}${PREFIX}/bin/$$f;			\
	done
	cd ${WRKSRC}/solver/310/${OPENOFFICE_OUTPATH}.pro/bin &&  \
	${INSTALL_DATA}	${OO_EXTENSIONS} ${DESTDIR}${OO_PREFIX}/extensions
	cd ${WRKSRC}/sysui/${OPENOFFICE_OUTPATH}.pro/misc/openoffice.org && \
	${SETENV} ${MAKE_ENV} DESTDIR=${DESTDIR} _PREFIX=${PREFIX}	\
		GNOME=${PKG_OPTIONS:Mgnome} KDE=${PKG_OPTIONS:Mkde}	\
		OO_PREFIX=${OO_PREFIX} ${SH} create_tree.sh

post-install:
	cd ${DESTDIR}${PREFIX} &&				\
	find lib/${OO_RELEASE} \! -type d -print |		\
	sort > ${WRKDIR}/PLIST

# OS specific Makefile
.if exists(Makefile.${OPSYS})
.  include "Makefile.${OPSYS}"
.endif

.include "../../mk/compiler.mk"

.include "../../databases/db4/buildlink3.mk"
.include "../../databases/openldap-client/buildlink3.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../devel/gperf/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/hunspell/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/raptor2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../www/neon/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
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
