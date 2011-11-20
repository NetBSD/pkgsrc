# $NetBSD: Makefile,v 1.16 2011/11/20 03:21:37 jym Exp $
#

VERSION=	3.3.2
DISTNAME=	xen-${VERSION}
PKGNAME=	xenkernel33-${VERSION}
PKGREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	http://bits.xensource.com/oss-xen/release/${VERSION}/
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	cegger@NetBSD.org
HOMEPAGE=	http://xen.org/
COMMENT=	Xen 3.3.2 Kernel

LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

ONLY_FOR_PLATFORM=	Linux-2.6*-i386 Linux-2.6*-x86_64
ONLY_FOR_PLATFORM+=	NetBSD-[5-9].*-x86_64 NetBSD-[5-9].*-i386

CONFLICTS=	xenkernel30-* xentools30-*
CONFLICTS+=	xenkernel3-*  xentools3-*
CONFLICTS+=	xenkernel32-* xentools32-*

WRKSRC=		${WRKDIR}/xen-${VERSION}

NO_CONFIGURE=	yes
USE_TOOLS+=	gmake

PYTHON_FOR_BUILD_ONLY=	# empty
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

do-build:
	cd ${WRKSRC} && ${GMAKE} debug=n xen
	${CP} ${WRKSRC}/dist/install/boot/xen.gz ${WRKDIR}/xen.gz
	cd ${WRKSRC} && ${GMAKE} clean && ${GMAKE} debug=y xen
	${CP} ${WRKSRC}/dist/install/boot/xen.gz ${WRKDIR}/xen-debug.gz

do-install:
	${INSTALL_DATA} ${WRKDIR}/xen.gz \
	    ${DESTDIR}${XENKERNELDIR}/xen.gz
	${INSTALL_DATA} ${WRKDIR}/xen-debug.gz \
	    ${DESTDIR}${XENKERNELDIR}/xen-debug.gz

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
