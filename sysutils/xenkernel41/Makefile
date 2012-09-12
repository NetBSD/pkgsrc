# $NetBSD: Makefile,v 1.12 2012/09/12 11:04:17 drochner Exp $
#

VERSION=	4.1.3
DISTNAME=	xen-${VERSION}
PKGNAME=	xenkernel41-${VERSION}
CATEGORIES=	sysutils
MASTER_SITES=	http://bits.xensource.com/oss-xen/release/${VERSION}/
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	cegger@NetBSD.org
HOMEPAGE=	http://xen.org/
COMMENT=	Xen 4.1.2 Kernel

LICENSE=        gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

ONLY_FOR_PLATFORM=	Linux-2.6*-i386 Linux-2.6*-x86_64
ONLY_FOR_PLATFORM+=	NetBSD-[5-9].*-x86_64 NetBSD-[5-9].*-i386

NO_CONFIGURE=	yes
USE_TOOLS+=	gmake

PYTHON_FOR_BUILD_ONLY=	# empty
PY_PATCHPLIST=		NO

# XXX Why does this not work?
# See work/xen-4.1.2/Config.mk:41 why PYTHON must be set and what for
MAKE_ENV+=	PYTHON=${PYTHONBIN:Q}
MAKE_ENV+=	OCAML_TOOLS=no

INSTALLATION_DIRS=	xen41-kernel
XENKERNELDIR=		${PREFIX}/${INSTALLATION_DIRS}

MESSAGE_SUBST+=		XENKERNELDIR=${XENKERNELDIR:Q}

do-build:
	cd ${WRKSRC}/xen && ${BUILD_MAKE_CMD} debug=n build
	${CP} ${WRKSRC}/xen/xen.gz ${WRKDIR}/xen.gz
	cd ${WRKSRC}/xen && ${MAKE_PROGRAM} clean
	cd ${WRKSRC}/xen && ${BUILD_MAKE_CMD} debug=y build
	${CP} ${WRKSRC}/xen/xen.gz ${WRKDIR}/xen-debug.gz

do-install:
	${INSTALL_DATA} ${WRKDIR}/xen.gz \
	    ${DESTDIR}${XENKERNELDIR}/xen.gz
	${INSTALL_DATA} ${WRKDIR}/xen-debug.gz \
	    ${DESTDIR}${XENKERNELDIR}/xen-debug.gz

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
