# $NetBSD: Makefile,v 1.2 2016/03/01 20:17:18 joerg Exp $

DISTNAME=	Catch-1.3.4
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=philsquared/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${MASTER_SITE_GITHUB:=philsquared/Catch/}
COMMENT=	C++-native, framework for unit-tests, TDD and BDD
LICENSE=	boost-license

EXTRACT_USING=	bsdtar

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_TOOLS+=	gmake

USE_LANGUAGES=	c c++

NO_BUILD=	yes

AUTO_MKDIRS=	yes

do-install:
	${RUN} ${INSTALL_DATA} ${WRKSRC}/single_include/catch.hpp \
		${DESTDIR}${PREFIX}/include

do-test:
	${RUN} cd ${WRKSRC}/projects/SelfTest && \
		${GMAKE} -f makefile && ./CatchSelfTest

.include "../../mk/bsd.pkg.mk"
