# $NetBSD: Makefile,v 1.24 2022/07/05 15:56:33 bouyer Exp $
#

# VERSION is set in xentool415/version.mk
.include		"../../sysutils/xentools415/version.mk"

PKGNAME=		xenstoretools-${VERSION}
CATEGORIES=		sysutils

MAINTAINER=		sborrill@NetBSD.org
HOMEPAGE=		http://xen.org/
COMMENT=		Xenstore Tools for Xen 4.15.x

LICENSE=		gnu-gpl-v2
DISTINFO_FILE=		${.CURDIR}/../../sysutils/xentools415/distinfo
PATCHDIR=		${.CURDIR}/../../sysutils/xentools415/patches
INSTALL_DIRS=		tools/xenstore tools/libs/toolcore tools/libs/store
INSTALL_DIRS+=		tools/libs/toollog tools/libs/call tools/libs/evtchn
INSTALL_DIRS+=		tools/libs/gnttab tools/libs/foreignmemory
INSTALL_DIRS+=		tools/libs/devicemodel tools/libs/ctrl tools/libs/guest
INSTALL_MAKE_FLAGS+=	XENSTORE_XENSTORED=n

.if !exists(/usr/bin/iasl)
BUILD_DEPENDS+=	acpica-utils-[0-9]*:../../sysutils/acpica-utils
.endif

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-rpath --disable-golang
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE}
# configure checks for more components than are required to build the
# xenstore subdirectory, so provide dummy args to allow it to complete
# without adding unnecessary dependencies
CONFIGURE_ARGS+=	ac_cv_path_AS86=/dummy
CONFIGURE_ARGS+=	ac_cv_path_LD86=/dummy
CONFIGURE_ARGS+=	ac_cv_path_BCC=/dummy
CONFIGURE_ARGS+=	ac_cv_lib_yajl_yajl_alloc=yes
CONFIGURE_ARGS+=	ac_cv_lib_z_deflateCopy=yes
CONFIGURE_ARGS+=	ac_cv_header_argp_h=yes
CONFIGURE_ARGS+=	ac_cv_lib_argp_argp_usage=yes
CONFIGURE_ARGS+=	pixman_CFLAGS=dummy
CONFIGURE_ARGS+=	pixman_LIBS=/dummy

PKG_SYSCONFSUBDIR=	xen
BUILD_DEFS+=		VARBASE

ONLY_FOR_PLATFORM=	Linux-2.6*-i386 Linux-2.6*-x86_64
ONLY_FOR_PLATFORM+=	NetBSD-[5-9].*-x86_64 NetBSD-[5-9].*-i386

CONFLICTS+=		libxen-[0-9]*
CONFLICTS+=		xentools20-[0-9]*
CONFLICTS+=		xentools3*
CONFLICTS+=		xentools4*

USE_TOOLS+=		bash gmake pkg-config perl bison

MAKE_ENV+=		PREFIX=${prefix:Q} WRKSRC=${WRKSRC}
MAKE_ENV+=		MV=${MV:Q} PYTHON=${PYTHONBIN:Q} SED=${SED:Q}
MAKE_ENV+=		VARBASE=${VARBASE}

RCD_SCRIPTS=		xendomname
FILES_SUBST+=		PREFIX=${PREFIX}

SUBST_CLASSES+=			rpath-link
SUBST_STAGE.rpath-link=		pre-configure
SUBST_MESSAGE.rpath-link=	Fixing rpath-link syntax
SUBST_FILES.rpath-link+=	tools/Rules.mk
SUBST_SED.rpath-link+=		-e 's/-rpath-link=/-rpath-link,/g'

.include "../../mk/bsd.prefs.mk"

INSTALLATION_DIRS=	bin include lib

do-build:
	cd ${WRKSRC}/ && ${BUILD_MAKE_CMD} build-tools-public-headers
	cd ${WRKSRC}/tools/libs/toolcore &&                             \
		${BUILD_MAKE_CMD} all
	cd ${WRKSRC}/tools/libs/store &&                                \
		${BUILD_MAKE_CMD} all
	cd ${WRKSRC}/tools/libs/toollog &&                              \
		${BUILD_MAKE_CMD} all
	cd ${WRKSRC}/tools/libs/call &&                                 \
		${BUILD_MAKE_CMD} all
	cd ${WRKSRC}/tools/libs/evtchn &&                               \
		${BUILD_MAKE_CMD} all
	cd ${WRKSRC}/tools/libs/gnttab &&                               \
		${BUILD_MAKE_CMD} all
	cd ${WRKSRC}/tools/libs/foreignmemory &&                        \
		${BUILD_MAKE_CMD} all
	cd ${WRKSRC}/tools/libs/devicemodel &&                          \
		${BUILD_MAKE_CMD} all
	cd ${WRKSRC}/tools/libs/ctrl &&                                 \
		${BUILD_MAKE_CMD} all
	cd ${WRKSRC}/tools/libs/guest &&                                \
		${BUILD_MAKE_CMD} all
	${RUN}${_ULIMIT_CMD}                                            \
	cd ${WRKSRC}/tools/xenstore  &&                                 \
		${BUILD_MAKE_CMD} clients

pre-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/lib/pkgconfig

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../devel/glib2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
