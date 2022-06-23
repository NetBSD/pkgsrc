# $NetBSD: Makefile,v 1.21 2022/06/23 16:20:05 bouyer Exp $

VERSION=	4.11.4
#keep >= 1 if we have security patches
PKGREVISION=	7
DISTNAME=	xen-${VERSION}
PKGNAME=	xenkernel411-${VERSION}
CATEGORIES=	sysutils
MASTER_SITES=	https://downloads.xenproject.org/release/xen/${VERSION}/
DIST_SUBDIR=	xen411

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	https://xenproject.org/
COMMENT=	Xen 4.11.x Kernel

LICENSE=	gnu-gpl-v2

ONLY_FOR_PLATFORM=	Linux-2.6*-x86_64
ONLY_FOR_PLATFORM+=	NetBSD-[5-9].*-x86_64

SSP_SUPPORTED=	no

NO_CONFIGURE=	yes
USE_TOOLS+=	gmake

PYTHON_FOR_BUILD_ONLY=		YES
PYTHON_VERSIONS_ACCEPTED=	27

MAKE_ENV+=	OCAML_TOOLS=no
.if defined(PKGREVISION) && !empty(PKGREVISION) && (${PKGREVISION} != "0")
MAKE_ENV+=	XEN_VENDORVERSION=nb${PKGREVISION}
.else
MAKE_ENV+=	XEN_VENDORVERSION=nb0
.endif

INSTALLATION_DIRS=	xen411-kernel
XENKERNELDIR=		${PREFIX}/${INSTALLATION_DIRS}

MESSAGE_SUBST+=		XENKERNELDIR=${XENKERNELDIR}

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
EXTRA_CFLAGS+=	-Qunused-arguments -no-integrated-as -Wno-error=format \
		-Wno-error=parentheses-equality -Wno-error=enum-conversion \
		-Wno-error=unused-function -Wno-error=unused-const-variable \
		-Wno-error=ignored-attributes -Wno-error=constant-conversion \
		-Wno-error=address-of-packed-member \
		-Wno-error=initializer-overrides \
		-Wno-error=tautological-compare
.elif !empty(PKGSRC_COMPILER:Mgcc)
EXTRA_CFLAGS+=	 -falign-functions=16
.endif

MAKE_ENV+=	EXTRA_CFLAGS=${EXTRA_CFLAGS:Q}

do-build:
	cd ${WRKSRC} && ${BUILD_MAKE_CMD} build-xen
	${CP} ${WRKSRC}/xen/xen.gz ${WRKDIR}/xen.gz
	cd ${WRKSRC} && ${MAKE_PROGRAM} clean
	echo "CONFIG_DEBUG=y" >> ${WRKSRC}/xen/.config
	echo "# CONFIG_CRASH_DEBUG is not set" >> ${WRKSRC}/xen/.config
	echo "# CONFIG_FRAME_POINTER is not set" >> ${WRKSRC}/xen/.config
	echo "# CONFIG_GCOV is not set" >> ${WRKSRC}/xen/.config
	echo "# CONFIG_LOCK_PROFILE is not set" >> ${WRKSRC}/xen/.config
	echo "# CONFIG_PERF_COUNTERS is not set" >> ${WRKSRC}/xen/.config
	echo "CONFIG_VERBOSE_DEBUG=y" >> ${WRKSRC}/xen/.config
	echo "CONFIG_SCRUB_DEBUG=y" >> ${WRKSRC}/xen/.config
	echo "# CONFIG_UBSAN is not set" >> ${WRKSRC}/xen/.config
	cd ${WRKSRC} && ${BUILD_MAKE_CMD} build-xen
	${CP} ${WRKSRC}/xen/xen.gz ${WRKDIR}/xen-debug.gz

do-install:
	${INSTALL_DATA} ${WRKDIR}/xen.gz \
	    ${DESTDIR}${XENKERNELDIR}/xen.gz
	${INSTALL_DATA} ${WRKDIR}/xen-debug.gz \
	    ${DESTDIR}${XENKERNELDIR}/xen-debug.gz

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
