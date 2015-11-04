# $NetBSD: Makefile,v 1.9.4.1 2015/11/04 21:22:27 bsiegert Exp $

VERSION=	4.5.1
DISTNAME=	xen-${VERSION}
PKGNAME=	xenkernel45-${VERSION}
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://bits.xensource.com/oss-xen/release/${VERSION}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xenproject.org/
COMMENT=	Xen 4.5.x Kernel

LICENSE=	gnu-gpl-v2

ONLY_FOR_PLATFORM=	Linux-2.6*-i386 Linux-2.6*-x86_64
ONLY_FOR_PLATFORM+=	NetBSD-[5-9].*-x86_64 NetBSD-[5-9].*-i386

NO_CONFIGURE=	yes
USE_TOOLS+=	gmake

PYTHON_FOR_BUILD_ONLY=		YES
PYTHON_VERSIONS_INCOMPATIBLE=	33 34

MAKE_ENV+=	OCAML_TOOLS=no

INSTALLATION_DIRS=	xen45-kernel
XENKERNELDIR=		${PREFIX}/${INSTALLATION_DIRS}

MESSAGE_SUBST+=		XENKERNELDIR=${XENKERNELDIR}

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
EXTRA_CFLAGS+=	-Qunused-arguments -no-integrated-as -Wno-error=format \
		-Wno-error=parentheses-equality -Wno-error=enum-conversion \
		-Wno-error=unused-function -Wno-error=unused-const-variable \
		-Wno-error=ignored-attributes -Wno-error=initializer-overrides
.endif

MAKE_ENV+=	EXTRA_CFLAGS=${EXTRA_CFLAGS:Q}

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
