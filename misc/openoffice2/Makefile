# $NetBSD: Makefile,v 1.1.1.1 2007/02/27 11:55:57 hira Exp $
#

OO_VER=			2.1.0
DISTNAME=		openoffice-${OO_VER}
PKGNAME=		openoffice2-${OO_VER}
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_OPENOFFICE:=stable/${OO_VER}/}
DIST_SUBDIR=		${DISTNAME}

DISTFILES=		OOo_${OO_VER}_src.tar.bz2
DISTFILES+=		OOo_${OO_VER}_src_binfilter.tar.bz2
#DISTFILES+=		OOo_${OO_VER}_src_sdk.tar.bz2
DISTFILES+=		OOo_${OO_VER}_src_system.tar.bz2
DISTFILES+=		OOo_${OO_VER}_src_l10n.tar.bz2
# Missing file from tarball...
DISTFILES+=		bridge.h
SITES.bridge.h=		http://www.openoffice.org/source/browse/%2Acheckout%2A/udk/bridges/inc/bridges/cpp_uno/Attic/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.openoffice.org/
COMMENT=		Integrated office productivity suite (version 2)

BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison
BUILD_DEPENDS+=		{standalone-tcsh,tcsh}-[0-9]*:../../shells/tcsh
BUILD_DEPENDS+=		zip-[0-9]*:../../archivers/zip
BUILD_DEPENDS+=		unzip-[0-9]*:../../archivers/unzip
BUILD_DEPENDS+=		p5-Archive-Zip-[0-9]*:../../archivers/p5-Archive-Zip

WRKSRC=			${WRKDIR}/OOE680_m6/config_office
GCC_REQD+=		3.0
USE_LANGUAGES+=		c c++

.include "../../mk/bsd.prefs.mk"

USE_TOOLS+=		gmake imake perl tar
PTHREAD_OPTS+=		require
PTHREAD_AUTO_VARS=	yes

CONFLICTS+=		staroffice-[0-9]*
CONFLICTS+=		openoffice-[0-9]*
CONFLICTS+=		openoffice-bin-[0-9]*
CONFLICTS+=		openoffice2-bin-[0-9]*
CONFLICTS+=		openoffice-linux-[0-9]*

ONLY_FOR_PLATFORM=	NetBSD-1.6Z[G-Z]*-i386 NetBSD-[2-9]*-i386

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-binfilter
CONFIGURE_ARGS+=	--disable-ldap

# `portable' supports all platforms.
CONFIGURE_ARGS+=	--enable-epm --with-package-format=portable

# XXX: Error in OOo internal libsndfile.
CONFIGURE_ARGS+=	--disable-pasf

# Disable Java.
CONFIGURE_ARGS+=	--without-java --disable-odk --disable-gcjaot

# NOTE: In this version, this value should be separated by space (comma
#       causes build error).
CONFIGURE_ARGS+=	--with-lang=${OPENOFFICE_LANGUAGE}

.include "options.mk"

UNLIMIT_RESOURCES+=	datasize

OPENOFFICE_VERSION=	OpenOffice.org${OO_VER}
PLIST_SRC+=		${WRKDIR}/.PLIST_SRC
MESSAGE_SUBST+=		OPENOFFICE_VERSION=${OPENOFFICE_VERSION}
INSTALLATION_DIRS=	bin

SUBST_CLASSES+=			X11_LDFLAGS
SUBST_MESSAGE.X11_LDFLAGS=	Adding X11_LDFLAGS.
SUBST_STAGE.X11_LDFLAGS=	post-patch
SUBST_FILES.X11_LDFLAGS=	../solenv/inc/${OPENOFFICE_OUTPATH:Q}.mk
SUBST_SED.X11_LDFLAGS=		-e 's|@X11_LDFLAGS@|${X11_LDFLAGS}|g'

OO_PKGPATH=${WRKSRC}/../instsetoo_native/${OPENOFFICE_OUTPATH}.pro/OpenOffice/portable/install/${OPENOFFICE_LANGUAGE}
OO_PKGROOT=/opt/openoffice.org2.1

post-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/bridge.h		\
		${WRKSRC}/../bridges/inc/bridges/cpp_uno/

do-build:
	${_ULIMIT_CMD} tcsh -c "setenv PTHREAD_DIAGASSERT Ael && cd ${WRKSRC}/.. && ./bootstrap && source ${OPENOFFICE_SETFILE}Env.Set && dmake build_all"

post-build:
	cd ${WRKDIR} &&				\
	${RM} -fr opt &&			\
	for f in ${OO_PKGPATH:Q}/*/*.sw; do	\
		${TAR} xpf $$f;			\
	done

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${OPENOFFICE_VERSION}
	cd ${WRKDIR}${OO_PKGROOT} &&					\
	${TAR} cf - . | ${TAR} Cxpf ${PREFIX}/${OPENOFFICE_VERSION} -
	for f in scalc sdraw simpress soffice swriter; do		\
		${LN} -sf ${PREFIX}/${OPENOFFICE_VERSION}/program/$$f	\
			${PREFIX}/bin/$$f;				\
	done

post-install:
	cd ${PREFIX} &&							\
	${FIND} ${OPENOFFICE_VERSION} \! -type d -print |		\
	${SORT} > ${PLIST_SRC} &&					\
	${FIND} ${OPENOFFICE_VERSION} -type d -print | ${SORT} -r |	\
	${AWK} '{print("@dirrm "$$1)}' >> ${PLIST_SRC}

# everything specific to your OS/Arch goes into its own Makefile
# group together i386, i486, i586 and i686 (for Linux)
#
ARCH=	${MACHINE_ARCH:C/i[3-6]86/i386/g}

.if exists(Makefile.${OPSYS}.${ARCH})
.  include "Makefile.${OPSYS}.${ARCH}"
.endif

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../mk/compiler.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
