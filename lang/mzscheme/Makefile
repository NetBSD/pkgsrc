# $NetBSD: Makefile,v 1.17 2006/10/01 14:47:43 rillig Exp $

DISTNAME=		mzscheme-205.src.unix
PKGNAME=		mzscheme-205
CATEGORIES=		lang
MASTER_SITES=		http://download.plt-scheme.org/bundles/205/mzscheme/

MAINTAINER=		pooka@NetBSD.org
HOMEPAGE=		http://www.plt-scheme.org/software/mzscheme/
COMMENT=		R5RS-compliant scheme

CONFLICTS+=		drscheme-[0-9]*

WRKSRC=			${WRKDIR}/plt
GNU_CONFIGURE=		yes
CONFIGURE_DIRS=		src
CONFIGURE_SCRIPT=	./configure
EXTRACT_USING=		pax

ONLY_FOR_PLATFORM=	NetBSD-*-i386
ONLY_FOR_PLATFORM+=	Linux-*-i386
ONLY_FOR_PLATFORM+=	SunOS-*-*

INSTALLATION_DIRS=	${PKGMANDIR}/man1

# setup-extension.ss is classified as precompiled, which it isn't.
_SUBST_IS_TEXT_FILE=	true

SUBST_CLASSES+=		mz
SUBST_STAGE.mz=		pre-configure
SUBST_MESSAGE.mz=	Adjusting installation prefix.
SUBST_FILES.mz=		man/man1/mzscheme.1 man/man1/help-desk.1
SUBST_FILES.mz+=	collects/make/setup-extension.ss
SUBST_FILES.mz+=	collects/slibinit/init.ss
SUBST_SED.mz=		-e 's@XXXPREFIXXXX@${PREFIX}@g'

do-install:
	cd ${WRKDIR}/plt/src/mzscheme && ${MAKE} normal-install
	${INSTALL_DATA_DIR} ${PREFIX}/include/mzscheme
	${INSTALL_DATA} ${WRKDIR}/plt/include/*.h ${PREFIX}/include/mzscheme
	${INSTALL_MAN} ${WRKDIR}/plt/man/man1/mzscheme.1 ${PREFIX}/${PKGMANDIR}/man1
	[ -d ${PREFIX}/lib/plt ] || ${INSTALL_DATA_DIR} ${PREFIX}/lib/plt
	cd ${WRKDIR}/plt && ${PAX} -wr -s ',.*\.orig$$,,' collects ${PREFIX}/lib/plt

.include "../../mk/bsd.pkg.mk"
