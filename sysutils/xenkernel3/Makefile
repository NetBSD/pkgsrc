# $NetBSD: Makefile,v 1.12 2008/04/25 20:11:17 tnn Exp $
#

VERSION=	3.1.3
DISTNAME=	xen-${VERSION}-src
PKGNAME=	xenkernel3-${VERSION}
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tgz

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://xen.org/
COMMENT=	Xen3 Kernel

ONLY_FOR_PLATFORM=	Linux-2.[46]*-i386 NetBSD-*-i386 Linux-2.[46]*-x86_64 NetBSD-*-x86_64
CONFLICTS=	xenkernel30-*


WRKSRC=		${WRKDIR}/xen-${VERSION}

NO_CONFIGURE=	yes
USE_TOOLS+=	gmake

PYTHON_VERSIONS_ACCEPTED= 25 24 23
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

do-build:
	cd ${WRKSRC} && ${GMAKE} XEN_TARGET_X86_PAE=n debug=n xen
	${CP} ${WRKSRC}/dist/install/boot/xen.gz ${WRKDIR}/xen.gz
	cd ${WRKSRC} && ${GMAKE} clean && \
	    ${GMAKE} XEN_TARGET_X86_PAE=n debug=y xen
	${CP} ${WRKSRC}/dist/install/boot/xen.gz ${WRKDIR}/xen-debug.gz

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/xen3-kernel
	${INSTALL_DATA} ${WRKDIR}/xen.gz ${PREFIX}/xen3-kernel/xen.gz
	${INSTALL_DATA} ${WRKDIR}/xen-debug.gz ${PREFIX}/xen3-kernel/xen-debug.gz

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
