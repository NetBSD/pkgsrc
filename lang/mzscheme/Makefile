# $NetBSD: Makefile,v 1.20 2008/01/23 01:53:06 rillig Exp $

DISTNAME=		mz-360-src-unix
PKGNAME=		mzscheme-360
CATEGORIES=		lang
MASTER_SITES=		http://download.plt-scheme.org/bundles/360/mz/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pooka@NetBSD.org
HOMEPAGE=		http://www.plt-scheme.org/software/mzscheme/
COMMENT=		R5RS-compliant scheme

CONFLICTS+=		drscheme-[0-9]*

WRKSRC=			${WRKDIR}/mz-360
GNU_CONFIGURE=		yes
CONFIGURE_DIRS=		src
CONFIGURE_SCRIPT=	./configure
# causes the build to use libtool
CONFIGURE_ARGS=		--enable-shared
USE_LIBTOOL=		yes
MAKE_JOBS_SAFE=		no

ONLY_FOR_PLATFORM=	NetBSD-*-i386
ONLY_FOR_PLATFORM+=	Linux-*-i386
ONLY_FOR_PLATFORM+=	SunOS-*-*

INSTALLATION_DIRS+=	${PREFIX}/share/doc/${PKGNAME}

SUBST_CLASSES+=		mz
SUBST_STAGE.mz=		pre-configure
SUBST_MESSAGE.mz=	Adjusting installation prefix.
SUBST_FILES.mz+=	collects/make/setup-extension.ss
SUBST_FILES.mz+=	collects/slibinit/init.ss
SUBST_FILES.mz+=	src/configure
SUBST_SED.mz=		-e 's@XXXPREFIXXXX@${PREFIX}@g'
SUBST_SED.mz+=		-e 's@XXXMZDOCDIRXXX@${PREFIX}/share/doc/${PKGNAME}@g'

LIBTOOL_OVERRIDE=	src/lt/libtool src/foreign/gcc/libffi/libtool

post-patch:
	${RM} ${WRKSRC}/collects/make/setup-extension.ss.orig
	${RM} ${WRKSRC}/collects/slibinit/init.ss.orig

.include "../../mk/bsd.pkg.mk"
