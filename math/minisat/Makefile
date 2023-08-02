# $NetBSD: Makefile,v 1.6 2023/08/02 19:21:55 nia Exp $

DISTNAME=	minisat-2.2.0
CATEGORIES=	math
MASTER_SITES=	http://minisat.se/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://minisat.se/
COMMENT=	Minimalistic yet highly efficient SAT solver
LICENSE=	mit

WRKSRC=		${WRKDIR}/minisat
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
#BUILD_DIRS=	core simp
BUILD_DIRS=	simp
MAKE_ENV=	MROOT=${WRKSRC}
MAKE_ENV+=	LFLAGS="-L${BUILDLINK_PREFIX.zlib}/lib ${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.zlib}/lib"
BUILD_TARGET=	# empty

# Fails with C++14 default language.
FORCE_CXX_STD=	c++03

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/simp/minisat \
		${DESTDIR}${PREFIX}/bin/minisat

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
