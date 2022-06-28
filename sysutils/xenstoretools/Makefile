# $NetBSD: Makefile,v 1.21 2022/06/28 11:36:07 wiz Exp $
#

# VERSION is set in xentool411/version.mk
PKGREVISION=		6
.include		"../../sysutils/xentools411/version.mk"

DIST_SUBDIR=		xen411
DISTNAME=		xen-${VERSION}
PKGNAME=		xenstoretools-${VERSION}
CATEGORIES=		sysutils
MASTER_SITES=		https://downloads.xenproject.org/release/xen/${VERSION}/

DISTFILES=		${DISTNAME}.tar.gz

XEN_EXTFILES=		http://xenbits.xensource.com/xen-extfiles/
DIST_IPXE=		ipxe-git-${VERSION_IPXE}.tar.gz
DISTFILES+=		${DIST_IPXE}
SITES.${DIST_IPXE} +=	${XEN_EXTFILES}

MAINTAINER=		sborrill@NetBSD.org
HOMEPAGE=		http://xen.org/
COMMENT=		Xenstore Tools for Xen 4.11.x

LICENSE=		gnu-gpl-v2
DISTINFO_FILE=		${.CURDIR}/../../sysutils/xentools411/distinfo
PATCHDIR=		${.CURDIR}/../../sysutils/xentools411/patches
INSTALL_DIRS=		tools/xenstore tools/libs/toolcore
INSTALL_MAKE_FLAGS+=	XENSTORE_XENSTORED=n

.if !exists(/usr/bin/iasl)
BUILD_DEPENDS+=	acpica-utils-[0-9]*:../../sysutils/acpica-utils
.endif

GNU_CONFIGURE=		yes
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

USE_TOOLS+=		bash gmake pkg-config perl

MAKE_ENV+=		PREFIX=${prefix:Q} WRKSRC=${WRKSRC}
MAKE_ENV+=		MV=${MV:Q} PYTHON=${PYTHONBIN:Q} SED=${SED:Q}
MAKE_ENV+=		VARBASE=${VARBASE}

RCD_SCRIPTS=		xendomname
FILES_SUBST+=		PREFIX=${PREFIX}

.include "../../mk/bsd.prefs.mk"

INSTALLATION_DIRS=	bin include lib

pre-build:
	${LN} -s ../../xen/include/public ${WRKSRC}/tools/include/xen

do-build:
	${RUN}${_ULIMIT_CMD}                                            \
	cd ${WRKSRC}/tools/libs/toolcore  &&                            \
		${BUILD_MAKE_CMD} all
	${RUN}${_ULIMIT_CMD}                                            \
	cd ${WRKSRC}/tools/xenstore  &&                                 \
		${BUILD_MAKE_CMD} clients

pre-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/pkgconfig

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../devel/glib2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
