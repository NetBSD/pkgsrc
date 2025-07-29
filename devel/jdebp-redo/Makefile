# $NetBSD: Makefile,v 1.7 2025/07/29 14:15:57 schmonz Exp $

DISTNAME=		redo-1.5
PKGNAME=		jdebp-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		https://jdebp.uk/Repository/netbsd/
DIST_SUBDIR=		${PKGNAME_NOREV}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://jdebp.info/Softwares/redo/
COMMENT=		C++ implementation of DJB's redo build tool
LICENSE=		isc OR 2-clause-bsd

WRKSRC=			${WRKDIR}

USE_LANGUAGES=		c++
USE_CXX_FEATURES=	c++11
FORCE_CXX_STD=		c++11
USE_TOOLS+=		pod2man

SUBST_CLASSES+=		pkgmandir
SUBST_STAGE.pkgmandir=	do-configure
SUBST_FILES.pkgmandir=	package/export
SUBST_SED.pkgmandir=	-e 's|"man/man1|${PKGMANDIR}"/man1|g'

do-configure:
	cd ${WRKSRC} && ./package/bsd/prepare
	${MKDIR} ${WRKSRC}/build
	${ECHO} ${CXX:Q} > ${WRKSRC}/build/cxx
	${ECHO} ${CPPFLAGS:Q} > ${WRKSRC}/build/cppflags
	${ECHO} ${CXXFLAGS:Q} > ${WRKSRC}/build/cxxflags
	${ECHO} ${LDFLAGS:Q} > ${WRKSRC}/build/ldflags

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./package/compile

do-install:
	cd ${WRKSRC} && ./package/export ${DESTDIR}${PREFIX}/
	cd ${WRKSRC} && ${SETENV} ${INSTALL_ENV} ${MAKE} -f bsd/rules stage
	for i in bin ${PKGMANDIR}/man1; do cd ${DESTDIR}${PREFIX}/$${i}; \
	  for j in *; do mv $${j} jdebp-$${j}; done; \
	done

.include "../../mk/bsd.pkg.mk"
