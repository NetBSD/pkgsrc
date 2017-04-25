# $NetBSD: Makefile,v 1.11 2017/04/25 06:49:45 sborrill Exp $
#

# VERSION is set in xentool46/version.mk
.include		"../../sysutils/xentools46/version.mk"

DISTNAME=	xen-${VERSION}
PKGNAME=	xenstoretools-${VERSION}
CATEGORIES=	sysutils
MASTER_SITES=	http://bits.xensource.com/oss-xen/release/${VERSION}/

DISTFILES=					${DISTNAME}.tar.gz
DISTFILES+=					ipxe-git-${VERSION_IPXE}.tar.gz
SITES.ipxe-git-${VERSION_IPXE}.tar.gz +=	http://xenbits.xensource.com/xen-extfiles/

MAINTAINER=		sborrill@NetBSD.org
HOMEPAGE=		http://xen.org/
COMMENT=		Xenstore Tools for Xen 4.6.x

LICENSE=		gnu-gpl-v2
DISTINFO_FILE=		${.CURDIR}/../../sysutils/xentools46/distinfo
PATCHDIR=		${.CURDIR}/../../sysutils/xentools46/patches
BUILD_DIRS=		xenstore
BUILD_TARGET=		clients
INSTALL_DIRS=		xenstore
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
WRKSRC=			${WRKDIR}/xen-${VERSION}/tools
BUILD_DEFS+=		VARBASE

ONLY_FOR_PLATFORM=	Linux-2.6*-i386 Linux-2.6*-x86_64
ONLY_FOR_PLATFORM+=	NetBSD-[5-9].*-x86_64 NetBSD-[5-9].*-i386

CONFLICTS+=		libxen-[0-9]*
CONFLICTS+=		xentools20-[0-9]*
CONFLICTS+=		xentools3*
CONFLICTS+=		xentools4*

USE_TOOLS+=		bash gmake pkg-config

MAKE_ENV+=		PREFIX=${prefix:Q} WRKSRC=${WRKSRC}
MAKE_ENV+=		MV=${MV:Q} PYTHON=${PYTHONBIN:Q} SED=${SED:Q}
MAKE_ENV+=		VARBASE=${VARBASE}

RCD_SCRIPTS=		xendomname
FILES_SUBST+=		PREFIX=${PREFIX}

.include "../../mk/bsd.prefs.mk"

INSTALLATION_DIRS=	bin include lib

pre-build:
	${LN} -s ../../xen/include/public ${WRKSRC}/xenstore/xen

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../devel/glib2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
