# $NetBSD: Makefile,v 1.6 2025/02/28 16:34:36 schmonz Exp $

DISTNAME=		redo-1.5
PKGNAME=		jdebp-${DISTNAME}
CATEGORIES=		devel
# 1.5 distfile was updated in place; instead, use the same one as FreeBSD and Void
MASTER_SITES=		${MASTER_SITE_LOCAL}

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
	cd ${WRKSRC} && ./package/prepare
	${ECHO} ${CXX:Q} > ${WRKSRC}/build/cxx
	${ECHO} ${CPPFLAGS:Q} > ${WRKSRC}/build/cppflags
	${ECHO} ${CXXFLAGS:Q} > ${WRKSRC}/build/cxxflags
	${ECHO} ${LDFLAGS:Q} > ${WRKSRC}/build/ldflags

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./package/make

do-install:
	cd ${WRKSRC} && ./package/makeinstall
	cd ${WRKSRC} && ./package/export ${DESTDIR}${PREFIX}/
	for i in bin ${PKGMANDIR}/man1; do cd ${DESTDIR}${PREFIX}/$${i}; \
	  for j in *; do mv $${j} jdebp-$${j}; done; \
	done

.include "../../mk/bsd.pkg.mk"
