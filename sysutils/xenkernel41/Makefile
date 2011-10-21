# $NetBSD: Makefile,v 1.4 2011/10/21 18:26:58 cegger Exp $
#

VERSION=	4.1.2
DISTNAME=	xen-${VERSION}
PKGNAME=	xenkernel41-${VERSION}
#PKGREVISION=	1
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

WRKSRC=		${WRKDIR}/xen-${VERSION}

NO_CONFIGURE=	yes
USE_TOOLS+=	gmake

PYTHON_FOR_BUILD_ONLY=	# empty
PY_PATCHPLIST=		NO

# XXX Why does this not work?
# See work/xen-4.1.2/Config.mk:41 why PYTHON must be set and what for
MAKE_ENV+=	PYTHON=${PYTHONBIN:Q}
MAKE_ENV+=	OCAML_TOOLS=no

INSTALLATION_DIRS=	xen41-kernel

do-build:
	cd ${WRKSRC} && ${BUILD_MAKE_CMD} debug=n xen
	${CP} ${WRKSRC}/dist/install/boot/xen.gz ${WRKDIR}/xen.gz
	cd ${WRKSRC}/xen && ${MAKE_PROGRAM} clean
	cd ${WRKSRC} && ${BUILD_MAKE_CMD} debug=y xen
	${CP} ${WRKSRC}/dist/install/boot/xen.gz ${WRKDIR}/xen-debug.gz

do-install:
	${INSTALL_DATA} ${WRKDIR}/xen.gz ${DESTDIR}${PREFIX}/${INSTALLATION_DIRS}/xen.gz
	${INSTALL_DATA} ${WRKDIR}/xen-debug.gz ${DESTDIR}${PREFIX}/${INSTALLATION_DIRS}/xen-debug.gz

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
