# $NetBSD: Makefile,v 1.32 2026/03/17 19:00:00 bouyer Exp $
#

# VERSION is set in xentool420/version.mk
#PKGREVISION=		1
.include		"../../sysutils/xentools420/version.mk"

PKGNAME=		xenstoretools-4.20_${VERSION}
CATEGORIES=		sysutils

MAINTAINER=		sborrill@NetBSD.org
HOMEPAGE=		http://xen.org/
COMMENT=		Xenstore Tools for Xen 4.20.x

LICENSE=		gnu-gpl-v2
DISTINFO_FILE=		${.CURDIR}/../../sysutils/xentools420/distinfo
PATCHDIR=		${.CURDIR}/../../sysutils/xentools420/patches
INSTALL_DIRS=		tools/xs-clients tools/libs/toolcore tools/libs/store
INSTALL_DIRS+=		tools/libs/toollog tools/libs/call tools/libs/evtchn
INSTALL_DIRS+=		tools/libs/gnttab tools/libs/foreignmemory
INSTALL_DIRS+=		tools/libs/devicemodel tools/libs/ctrl tools/libs/guest
INSTALL_MAKE_FLAGS+=	XENSTORE_XENSTORED=n

.if !exists(/usr/bin/iasl)
TOOL_DEPENDS+=	acpica-utils-[0-9]*:../../sysutils/acpica-utils
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
ONLY_FOR_PLATFORM+=	NetBSD-[15-9]*-x86_64 NetBSD-[15-9]*-i386
ONLY_FOR_PLATFORM+=	FreeBSD-1*-x86_64

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

post-extract:
	${MV} ${WRKDIR}/${QEMU_DIST} ${WRKSRC}/tools/qemu-xen
#${MV} ${WRKDIR}/${QEMUTRAD_DIST} ${WRKSRC}/tools/qemu-xen-traditional

pre-build:
	rm -f ${WRKSRC}/check/check_x11_devel
	${SED} -e "s,@XENDCONFDIR@,${PKG_SYSCONFDIR},g" \
		${WRKSRC}/docs/man/xenstore-chmod.1.pod |\
	    pod2man -n xenstore-chmod >${WRKDIR}/xenstore-chmod.1
	${SED} -e "s,@XENDCONFDIR@,${PKG_SYSCONFDIR},g" \
		${WRKSRC}/docs/man/xenstore-ls.1.pod |\
	    pod2man -n xenstore-ls >${WRKDIR}/xenstore-ls.1
	${SED} -e "s,@XENDCONFDIR@,${PKG_SYSCONFDIR},g" \
		${WRKSRC}/docs/man/xenstore.1.pod |\
	    pod2man -n xenstore >${WRKDIR}/xenstore.1
	${SED} -e "s,@XENDCONFDIR@,${PKG_SYSCONFDIR},g" \
		${WRKSRC}/docs/man/xentop.1.pod |\
	    pod2man -n xentop >${WRKDIR}/xentop.1
	${SED} -e "s,@XENDCONFDIR@,${PKG_SYSCONFDIR},g" \
		${WRKSRC}/docs/man/xentrace.8.pod |\
	    pod2man -n xentrace >${WRKDIR}/xentrace.8
	${SED} -e "s,@XENDCONFDIR@,${PKG_SYSCONFDIR},g" \
		${WRKSRC}/docs/man/xl.cfg.5.pod.in |\
	    pod2man -n xl.cfg >${WRKDIR}/xl.cfg.5
	${SED} -e "s,@XENDCONFDIR@,${PKG_SYSCONFDIR},g" \
		${WRKSRC}/docs/man/xl.conf.5.pod |\
	    pod2man -n xl.conf >${WRKDIR}/xl.conf.5
	${SED} -e "s,@XENDCONFDIR@,${PKG_SYSCONFDIR},g" \
		${WRKSRC}/docs/man/xl.1.pod.in |\
	    pod2man -n xl >${WRKDIR}/xl.1
	${SED} -e "s,@XENDCONFDIR@,${PKG_SYSCONFDIR},g" \
		${WRKSRC}/docs/man/xlcpupool.cfg.5.pod |\
	    pod2man -n xlcpupool.cfg >${WRKDIR}/xlcpupool.cfg.5
	${SED} -e "s,@XENDCONFDIR@,${PKG_SYSCONFDIR},g" \
		${WRKSRC}/docs/man/xl-disk-configuration.5.pod |\
	    pod2man -n xl-disk-configuration >${WRKDIR}/xl-disk-configuration.5


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
	cd ${WRKSRC}/tools/xs-clients  &&                                 \
		${BUILD_MAKE_CMD} clients

pre-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/lib/pkgconfig

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../devel/glib2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
