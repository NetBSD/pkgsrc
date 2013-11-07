# $NetBSD: Makefile,v 1.27 2013/11/07 00:47:39 joerg Exp $
#

VERSION=	3.1.4
DISTNAME=	xen-${VERSION}
PKGNAME=	xenkernel3-${VERSION}
PKGREVISION=	8
CATEGORIES=	sysutils
MASTER_SITES=	http://bits.xensource.com/oss-xen/release/${VERSION}/

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://xen.org/
COMMENT=	Xen3 Kernel

ONLY_FOR_PLATFORM=	Linux-2.[46]*-i386 NetBSD-*-i386 Linux-2.[46]*-x86_64 NetBSD-*-x86_64
CONFLICTS=	xenkernel30-[0-9]*

LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/xen-${VERSION}

NO_CONFIGURE=	yes
USE_TOOLS+=	gmake

PYTHON_FOR_BUILD_ONLY=	YES
PY_PATCHPLIST=		NO

SUBST_CLASSES+=		py
SUBST_STAGE.py=		pre-build
SUBST_FILES.py=		xen/include/public/foreign/Makefile
SUBST_FILES.py+=	xen/tools/get-fields.sh
SUBST_SED.py=		-e "s,python,${PYTHONBIN},g"

#PY_PATCHPLIST doesn't work because we have NO_CONFIGURE
SUBST_CLASSES+=		py2
SUBST_STAGE.py2=	pre-build
SUBST_FILES.py2=	xen/tools/compat-build-source.py
SUBST_FILES.py2+=	xen/tools/compat-build-header.py
SUBST_SED.py2=		-e "s,/usr/bin/python,${PYTHONBIN},g"

.if  ${MACHINE_ARCH} == "x86_64"
USE_TOOLS+=		bash
SUBST_CLASSES+=		bash
SUBST_STAGE.bash=	pre-build
SUBST_FILES.bash=	xen/include/Makefile
SUBST_SED.bash=		-e "s,/bin/bash,${PREFIX}/bin/bash,g"
.endif

.if  ${MACHINE_ARCH} == "i386"
PLIST_SRC=		PLIST.i386 PLIST
.else
PLIST_SRC=		PLIST
.endif

INSTALLATION_DIRS+= 	xen3-kernel
XENKERNELDIR=		${PREFIX}/xen3-kernel

MESSAGE_SUBST+=		XENKERNELDIR=${XENKERNELDIR:Q}

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
EXTRA_CFLAGS+=	-Wno-error=ignored-attributes -Wno-error=format \
		-Wno-error=tautological-compare \
		-Wno-error=parentheses-equality \
		-Wno-error=sometimes-uninitialized -no-integrated-as \
		-ffreestanding -Wno-error=unused-function
BUILDLINK_TRANSFORM+=	rm:-fno-reorder-blocks
.endif

do-build:
	cd ${WRKSRC} && \
	    EXTRA_CFLAGS=${EXTRA_CFLAGS:Q} ${GMAKE} XEN_TARGET_X86_PAE=n debug=n xen
	${CP} ${WRKSRC}/dist/install/boot/xen.gz ${WRKDIR}/xen.gz
	cd ${WRKSRC} && ${GMAKE} clean && \
	    EXTRA_CFLAGS=${EXTRA_CFLAGS:Q} ${GMAKE} XEN_TARGET_X86_PAE=n debug=y xen
	${CP} ${WRKSRC}/dist/install/boot/xen.gz ${WRKDIR}/xen-debug.gz
.if  ${MACHINE_ARCH} == "i386"
	cd ${WRKSRC} && ${GMAKE} clean && \
	    EXTRA_CFLAGS=${EXTRA_CFLAGS:Q} ${GMAKE} XEN_TARGET_X86_PAE=y debug=n xen
	${CP} ${WRKSRC}/dist/install/boot/xen.gz ${WRKDIR}/xen-PAE.gz
	cd ${WRKSRC} && ${GMAKE} clean && \
	    EXTRA_CFLAGS=${EXTRA_CFLAGS:Q} ${GMAKE} XEN_TARGET_X86_PAE=y debug=y xen
	${CP} ${WRKSRC}/dist/install/boot/xen.gz ${WRKDIR}/xen-PAE-debug.gz
.endif

do-install:
	${INSTALL_DATA} ${WRKDIR}/xen.gz \
	    ${DESTDIR}${XENKERNELDIR}/xen.gz
	${INSTALL_DATA} ${WRKDIR}/xen-debug.gz \
	    ${DESTDIR}${XENKERNELDIR}/xen-debug.gz
.if  ${MACHINE_ARCH} == "i386"
	${INSTALL_DATA} ${WRKDIR}/xen-PAE.gz \
	    ${DESTDIR}${XENKERNELDIR}/xen-PAE.gz
	${INSTALL_DATA} ${WRKDIR}/xen-PAE-debug.gz \
	    ${DESTDIR}${XENKERNELDIR}/xen-PAE-debug.gz
.endif

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
