# $NetBSD: Makefile,v 1.25 2013/11/07 00:47:39 joerg Exp $
#

VERSION=	3.3.2
DISTNAME=	xen-${VERSION}
PKGNAME=	xenkernel33-${VERSION}
PKGREVISION=	7
CATEGORIES=	sysutils
MASTER_SITES=	http://bits.xensource.com/oss-xen/release/${VERSION}/

MAINTAINER=	cegger@NetBSD.org
HOMEPAGE=	http://xen.org/
COMMENT=	Xen 3.3.2 Kernel

LICENSE=	gnu-gpl-v2

ONLY_FOR_PLATFORM=	Linux-2.6*-i386 Linux-2.6*-x86_64
ONLY_FOR_PLATFORM+=	NetBSD-[5-9].*-x86_64 NetBSD-[5-9].*-i386

CONFLICTS=	xenkernel30-* xentools30-*
CONFLICTS+=	xenkernel3-*  xentools3-*
CONFLICTS+=	xenkernel32-* xentools32-*

WRKSRC=		${WRKDIR}/xen-${VERSION}

NO_CONFIGURE=	yes
USE_TOOLS+=	gmake

PYTHON_FOR_BUILD_ONLY=	yes
PY_PATCHPLIST=		NO

SUBST_CLASSES+=		py
SUBST_STAGE.py=		pre-build
SUBST_FILES.py+=	xen/tools/get-fields.sh
SUBST_SED.py=		-e "s,python,${PYTHONBIN},g"

#PY_PATCHPLIST doesn't work because we have NO_CONFIGURE
SUBST_CLASSES+=		py2
SUBST_STAGE.py2=	pre-build
SUBST_FILES.py2=	xen/tools/compat-build-source.py
SUBST_FILES.py2+=	xen/tools/compat-build-header.py
SUBST_SED.py2=		-e "s,/usr/bin/env python,${PYTHONBIN},g"

INSTALLATION_DIRS=	xen3-kernel
XENKERNELDIR=		${PREFIX}/${INSTALLATION_DIRS}

MESSAGE_SUBST+=		XENKERNELDIR=${XENKERNELDIR:Q}

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
EXTRA_CFLAGS+=	-Qunused-arguments -no-integrated-as -Wno-error=format \
		-Wno-error=parentheses-equality -Wno-error=enum-conversion \
		-Wno-error=tautological-compare -Wno-error=unused-function
BUILDLINK_TRANSFORM+=	rm:-fno-reorder-blocks
.endif

do-build:
	cd ${WRKSRC} && EXTRA_CFLAGS=${EXTRA_CFLAGS:Q} ${GMAKE} debug=n xen
	${CP} ${WRKSRC}/dist/install/boot/xen.gz ${WRKDIR}/xen.gz
	cd ${WRKSRC} && ${GMAKE} clean
	cd ${WRKSRC} && EXTRA_CFLAGS=${EXTRA_CFLAGS:Q} ${GMAKE} debug=y xen
	${CP} ${WRKSRC}/dist/install/boot/xen.gz ${WRKDIR}/xen-debug.gz

do-install:
	${INSTALL_DATA} ${WRKDIR}/xen.gz \
	    ${DESTDIR}${XENKERNELDIR}/xen.gz
	${INSTALL_DATA} ${WRKDIR}/xen-debug.gz \
	    ${DESTDIR}${XENKERNELDIR}/xen-debug.gz

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
