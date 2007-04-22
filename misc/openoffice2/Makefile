# $NetBSD: Makefile,v 1.16 2007/04/22 23:15:24 hira Exp $
#

OO_VER=			2.2.0
PKGREVISION=		1
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
# Missing file from tarball...
DISTFILES+=		bridge.h
SITES.bridge.h=		http://www.openoffice.org/source/browse/%2Acheckout%2A/udk/bridges/inc/bridges/cpp_uno/Attic/

MAINTAINER=		hira@NetBSD.org
HOMEPAGE=		http://www.openoffice.org/
COMMENT=		Integrated office productivity suite (version 2)

BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison
BUILD_DEPENDS+=		zip-[0-9]*:../../archivers/zip
BUILD_DEPENDS+=		unzip-[0-9]*:../../archivers/unzip
BUILD_DEPENDS+=		p5-Archive-Zip-[0-9]*:../../archivers/p5-Archive-Zip

.include "../../mk/bsd.prefs.mk"

WRKSRC=			${WRKDIR}/OOF680_m14
CONFIGURE_DIRS=		config_office

# Cannot compile with 3.3.x (GCC Bugzilla Bug 16879).
GCC_REQD+=		3.4
USE_LANGUAGES+=		c c++

USE_TOOLS+=		bash gmake imake perl pkg-config tar
PTHREAD_OPTS+=		require
PTHREAD_AUTO_VARS=	yes

CONFLICTS+=		staroffice-[0-9]*
CONFLICTS+=		openoffice-[0-9]*
CONFLICTS+=		openoffice-bin-[0-9]*
CONFLICTS+=		openoffice2-bin-[0-9]*
CONFLICTS+=		openoffice-linux-[0-9]*

ONLY_FOR_PLATFORM=	NetBSD-1.6Z[G-Z]*-i386 NetBSD-[2-9]*-i386

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		X_LIBS=${X11_LDFLAGS:M*:Q}
CONFIGURE_ARGS+=	--with-use-shell=bash
CONFIGURE_ARGS+=	--enable-binfilter
CONFIGURE_ARGS+=	--enable-cairo
CONFIGURE_ARGS+=	--disable-ldap
CONFIGURE_ARGS+=	--with-system-freetype
CONFIGURE_ARGS+=	--with-system-libwpd

# `portable' supports all platforms.
CONFIGURE_ARGS+=	--enable-epm --with-package-format=portable

# XXX: Error in OOo internal libsndfile.
CONFIGURE_ARGS+=	--disable-pasf --without-nas

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

OO_UNXNAME=	openoffice.org2.2
OO_PKGPATH=	${WRKSRC}/instsetoo_native/${OPENOFFICE_OUTPATH}.pro/OpenOffice/portable/install
OO_PKGROOT=	/opt/${OO_UNXNAME}
OO_PROGRAMS=	scalc sdraw simpress soffice swriter unopkg

post-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/bridge.h		\
		${WRKSRC}/bridges/inc/bridges/cpp_uno/

do-build:
	${_ULIMIT_CMD} ${SETENV} ${MAKE_ENV} bash -c "export PTHREAD_DIAGASSERT=Ael && cd ${WRKSRC} && ./bootstrap && source ${OPENOFFICE_SETFILE}Env.Set.sh && dmake build_all"

post-build:
	cd ${WRKDIR} &&						\
	${RM} -fr opt &&					\
	for l in ${OO_LANGS}; do				\
		for f in ${OO_PKGPATH:Q}/$${l}/*/*.sw; do	\
			${TAR} xpfk $$f;			\
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
	${TAR} cf - . | ${TAR} Cxpf ${PREFIX}/${OO_RELEASE} -
	for f in ${OO_PROGRAMS}; do				\
		${LN} -sf ${PREFIX}/${OO_RELEASE}/program/$$f	\
			${PREFIX}/bin/$$f;			\
	done
	${INSTALL_SCRIPT} ${WRKDIR}/${OO_UNXNAME} ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/${OO_UNXNAME}-printeradmin	\
		${PREFIX}/bin

post-install:
	cd ${PREFIX} &&						\
	${FIND} ${OO_RELEASE} \! -type d -print |		\
	${SORT} > ${PLIST_SRC} &&				\
	${FIND} ${OO_RELEASE} -type d -print | ${SORT} -r |	\
	${AWK} '{print("@dirrm "$$1)}' >> ${PLIST_SRC}
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

.include "../../converters/libwpd/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
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
.include "../../mk/compiler.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
