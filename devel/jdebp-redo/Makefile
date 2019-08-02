# $NetBSD: Makefile,v 1.2 2019/08/02 21:54:56 schmonz Exp $

DISTNAME=	redo-1.4
PKGNAME=	jdebp-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	https://jdebp.eu/Repository/freebsd/

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://jdebp.eu/Softwares/redo/
COMMENT=	C++ implementation of DJB's redo build tool
LICENSE=	isc OR 2-clause-bsd

CONFLICTS+=	apenwarr-redo-[0-9]*

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

.include "../../mk/bsd.pkg.mk"
