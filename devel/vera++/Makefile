# $NetBSD: Makefile,v 1.35 2022/01/10 01:46:30 ryoon Exp $
#

DISTNAME=	vera++-1.1.1
PKGREVISION=	28
CATEGORIES=	devel
#MASTER_SITES=	http://www.inspirel.com/vera/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.inspirel.com/vera/
COMMENT=	Programmable verification and analysis tool for C++

BUILD_TARGET=	build
LICENSE=	boost-license
USE_LANGUAGES=	c++11
USE_TOOLS+=	gmake pax

CXXFLAGS+=	-DVERA_ROOT=\"${PREFIX:Q}/share/vera++\"

LIBS_DIRS=	-L${BUILDLINK_PREFIX.boost-libs:Q}/lib
LIBS_DIRS+=	${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.boost-libs:Q}/lib
LIBS_DIRS+=	-L${BUILDLINK_PREFIX.tcl:Q}/lib
LIBS_DIRS+=	${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.tcl:Q}/lib

MAKE_FLAGS+=	BOOST_DIR=${BUILDLINK_PREFIX.boost-headers}/include
MAKE_FLAGS+=	COMPILER_RPATH_FLAG=${COMPILER_RPATH_FLAG}
MAKE_FLAGS+=	LIBS_DIRS="${LIBS_DIRS}"
MAKE_FLAGS+=	TCLINCLUDE_DIR=${BUILDLINK_PREFIX.tcl}/include

INSTALLATION_DIRS=	bin share/doc/vera++ share/vera++

post-extract:
	cd ${WRKSRC} && find . -type f -exec chmod a-x {} \;

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vera++ ${DESTDIR}${PREFIX}/bin/vera++
	cd ${WRKSRC}/doc && pax -rw * ${DESTDIR}${PREFIX}/share/doc/vera++/
	cd ${WRKSRC} && \
	    pax -rw profiles scripts ${DESTDIR}${PREFIX}/share/vera++/

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
