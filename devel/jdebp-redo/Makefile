# $NetBSD: Makefile,v 1.5 2022/01/06 08:56:15 schmonz Exp $

DISTNAME=	redo-1.4
PKGNAME=	jdebp-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://jdebp.info/Repository/freebsd/

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://jdebp.info/Softwares/redo/
COMMENT=	C++ implementation of DJB's redo build tool
LICENSE=	isc OR 2-clause-bsd

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	c++
USE_TOOLS+=	pod2man

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
