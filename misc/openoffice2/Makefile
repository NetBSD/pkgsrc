# $NetBSD: Makefile,v 1.36 2008/01/18 22:31:41 hira Exp $
#

OO_VER=			2.3.1
PKGREVISION=		3
DISTNAME=		openoffice-${OO_VER}
PKGNAME=		openoffice2-${OO_VER}
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_OPENOFFICE:=stable/${OO_VER}/}
DIST_SUBDIR=		${DISTNAME}

DISTFILES=		OOo_${OO_VER}_src_core.tar.bz2
DISTFILES+=		OOo_${OO_VER}_src_binfilter.tar.bz2
DISTFILES+=		OOo_${OO_VER}_src_l10n.tar.bz2
#DISTFILES+=		OOo_${OO_VER}_src_sdk.tar.bz2
DISTFILES+=		OOo_${OO_VER}_src_system.tar.bz2

MAINTAINER=		hira@NetBSD.org
HOMEPAGE=		http://www.openoffice.org/
COMMENT=		Integrated office productivity suite (version 2)

BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison
BUILD_DEPENDS+=		zip-[0-9]*:../../archivers/zip
BUILD_DEPENDS+=		unzip-[0-9]*:../../archivers/unzip
BUILD_DEPENDS+=		p5-Archive-Zip-[0-9]*:../../archivers/p5-Archive-Zip

DEPENDS+=		libpaper-[0-9]*:../../print/libpaper

.include "../../mk/bsd.prefs.mk"

WRKSRC=			${WRKDIR}/OOG680_m9
CONFIGURE_DIRS=		config_office

# Cannot compile with 3.3.x (GCC Bugzilla Bug 16879).
GCC_REQD+=		3.4
USE_LANGUAGES+=		c c++

.include "../../mk/compiler.mk"

USE_TOOLS+=		bash gmake imake perl pkg-config tar
PTHREAD_OPTS+=		require
PTHREAD_AUTO_VARS=	yes

CONFLICTS+=		staroffice-[0-9]*
CONFLICTS+=		openoffice-[0-9]*
CONFLICTS+=		openoffice-bin-[0-9]*
CONFLICTS+=		openoffice2-bin-[0-9]*
CONFLICTS+=		openoffice-linux-[0-9]*

ONLY_FOR_PLATFORM=	NetBSD-1.6Z[G-Z]*-i386 NetBSD-[2-9]*-i386
ONLY_FOR_PLATFORM+=	NetBSD-1.6Z[G-Z]*-x86_64 NetBSD-[2-9]*-x86_64

GNU_CONFIGURE=		yes

SUBST_CLASSES+=		lib
SUBST_STAGE.lib=	post-patch
SUBST_MESSAGE.lib=	Adding library paths
SUBST_FILES.lib=	solenv/inc/libs.mk
.for pkg in db4 expat jpeg zlib
SUBST_SED.lib+=		-e 's,@BLNK_PREFIX_${pkg}@,${BUILDLINK_PREFIX.${pkg}},g'
LIBS+=			-L${BUILDLINK_PREFIX.${pkg}}/lib
LIBS+=			${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.${pkg}}/lib
.endfor

SUBST_CLASSES+=		python
SUBST_STAGE.python=	post-patch
SUBST_MESSAGE.python=	Fix python path
SUBST_FILES.python=	scripting/source/pyprov/mailmerge.py
SUBST_SED.python+=	-e 's,^\#!/bin/python$$,\#!${PYTHONBIN:Q},'

CONFIGURE_ENV+=		LIBS=${LIBS:O:u:Q}
CONFIGURE_ENV+=		X_LIBS=${X11_LDFLAGS:M*:Q}
CONFIGURE_ENV+=		BLNK_PREFIX_db4=${BUILDLINK_PREFIX.db4}
CONFIGURE_ENV+=		BLNK_PREFIX_nas=${BUILDLINK_PREFIX.nas}

CONFIGURE_ARGS+=	--with-use-shell=bash
CONFIGURE_ARGS+=	--enable-binfilter
CONFIGURE_ARGS+=	--enable-cairo
CONFIGURE_ARGS+=	--disable-ldap
CONFIGURE_ARGS+=	--with-system-stdlibs
CONFIGURE_ARGS+=	--with-system-curl
CONFIGURE_ARGS+=	--with-system-db
CONFIGURE_ARGS+=	--with-system-expat
CONFIGURE_ARGS+=	--with-system-freetype
CONFIGURE_ARGS+=	--with-system-jpeg
CONFIGURE_ARGS+=	--with-system-libxml2
CONFIGURE_ARGS+=	--with-system-libxslt
CONFIGURE_ARGS+=	--with-system-neon
CONFIGURE_ARGS+=	--with-system-python
CONFIGURE_ARGS+=	--with-system-zlib
CONFIGURE_ARGS+=	--with-dynamic-xinerama

# `portable' supports all platforms.
CONFIGURE_ARGS+=	--enable-epm --with-package-format=portable

# XXX: Error in OOo internal libsndfile.
CONFIGURE_ARGS+=	--disable-pasf

# systray quickstarter is broken with mutex handling.
CONFIGURE_ARGS+=	--disable-systray

# Disable Java.
CONFIGURE_ARGS+=	--without-java --disable-odk --disable-gcjaot

# NOTE: In this version, this value should be separated by space (comma
#       causes build error).
CONFIGURE_ARGS+=	--with-lang=${OO_LANGS:Q}

.include "options.mk"

UNLIMIT_RESOURCES+=	datasize

OO_RELEASE=		OpenOffice.org${OO_VER}
PLIST_SRC+=		${WRKDIR}/.PLIST_SRC
MESSAGE_SUBST+=		OO_RELEASE=${OO_RELEASE}
INSTALLATION_DIRS=	bin

OO_UNXNAME=	openoffice.org2.3
OO_PKGPATH=	${WRKSRC}/instsetoo_native/${OPENOFFICE_OUTPATH}.pro/OpenOffice/portable/install
OO_PKGROOT=	/opt/${OO_UNXNAME}
OO_PROGRAMS=	scalc sdraw simpress soffice swriter unopkg

post-extract:
	cd ${WRKSRC}/bridges/source/cpp_uno &&			\
	mv gcc3_netbsd_intel gcc3_netbsd_intel.orig &&		\
	cp -Rp gcc3_freebsd_intel gcc3_netbsd_intel &&		\
	cp -Rp gcc3_freebsd_x86-64 gcc3_netbsd_x86-64

do-build:
	${_ULIMIT_CMD} ${SETENV} ${MAKE_ENV} bash -c "cd ${WRKSRC} && ./bootstrap && source ${OPENOFFICE_SETFILE}Env.Set.sh && dmake build_all"

post-build:
	cd ${WRKDIR} &&						\
	rm -fr opt &&						\
	for l in ${OO_LANGS}; do				\
		for f in ${OO_PKGPATH:Q}/$${l}/*/*.sw; do	\
			tar xpfk $$f;				\
		done;						\
	done
	${ECHO} "#!${SH}" > ${WRKDIR}/${OO_UNXNAME}
	${ECHO} "exec ${PREFIX}/${OO_RELEASE}/program/soffice \"\$$@\""	\
		>> ${WRKDIR}/${OO_UNXNAME}
	${ECHO} "#!${SH}" > ${WRKDIR}/${OO_UNXNAME}-printeradmin
	${ECHO} "exec ${PREFIX}/${OO_RELEASE}/program/spadmin"	\
		>> ${WRKDIR}/${OO_UNXNAME}-printeradmin

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${OO_RELEASE}
	cd ${WRKDIR}${OO_PKGROOT} &&				\
	tar cf - . | tar Cxpf ${PREFIX}/${OO_RELEASE} -
	for f in ${OO_PROGRAMS}; do				\
		ln -sf ${PREFIX}/${OO_RELEASE}/program/$$f	\
			${PREFIX}/bin/$$f;			\
	done
	${INSTALL_SCRIPT} ${WRKDIR}/${OO_UNXNAME} ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/${OO_UNXNAME}-printeradmin	\
		${PREFIX}/bin

post-install:
	cd ${PREFIX} &&						\
	find ${OO_RELEASE} \! -type d -print |			\
	sort > ${PLIST_SRC} &&					\
	find ${OO_RELEASE} -type d -print | sort -r |		\
	awk '{print("@dirrm "$$1)}' >> ${PLIST_SRC}
	for f in ${OO_PROGRAMS}; do				\
		${ECHO} bin/$$f >> ${PLIST_SRC};		\
	done
	${ECHO} bin/${OO_UNXNAME} >> ${PLIST_SRC}
	${ECHO} bin/${OO_UNXNAME}-printeradmin >> ${PLIST_SRC}

# everything specific to your OS/Arch goes into its own Makefile
# group together i386, i486, i586 and i686 (for Linux)
#
ARCH=	${MACHINE_ARCH:C/i[3-6]86/i386/g}

.if exists(Makefile.${OPSYS}.${ARCH})
.  include "Makefile.${OPSYS}.${ARCH}"
.endif

# *.pc files are required, but these don't exist on NetBSD.
.if ${OPSYS} == "NetBSD" && defined(X11_TYPE) && !empty(X11_TYPE:Mnative)
USE_BUILTIN.freetype2=	no
USE_BUILTIN.Xfixes=     no
USE_BUILTIN.Xrandr=     no
USE_BUILTIN.Xrender=    no
.endif

PYTHON_VERSIONS_ACCEPTED=	24 23 22
.include "../../lang/python/application.mk"

.include "../../databases/db4/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
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
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
