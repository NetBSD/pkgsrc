# $NetBSD: Makefile,v 1.1.1.1 2002/12/11 19:03:17 cjep Exp $
#

DISTNAME=	opencxx2512
PKGNAME=	openc++-2.5.12
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=opencxx/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.csg.is.titech.ac.jp/~chiba/openc++.html
COMMENT=	OpenC++ is a version of C++ with a Metaobject Protocol

WRKSRC=		${WRKDIR}/openc++2.5.12/src/Unix

USE_GMAKE=	YES
MAKEFILE=	Makefile.SunOSandBSD
MAKE_FLAGS+=	CXXFLAGS=-I${PREFIX}/include
MAKE_FLAGS+=	GCLIBDIR=${BUILDLINK_DIR}

USE_BUILDLINK2= YES

OPENCXX_SHAREDIR=	${PREFIX}/share/openc++

post-build:
	${MV} ${WRKSRC}/../../sample/Makefile ${WRKSRC}/../../sample/Makefile.temp
	${SED} -e "s|__LOCALBASE__|${LOCALBASE}|g" ${WRKSRC}/../../sample/Makefile.temp >${WRKSRC}/../../sample/Makefile
	${RM} -f ${WRKSRC}/../../sample/Makefile.orig ${WRKSRC}/../../sample/Makefile.temp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/opencxx.a ${PREFIX}/lib/opencxx.a
	${INSTALL_PROGRAM} ${WRKSRC}/occ ${PREFIX}/bin/occ
	${INSTALL_DATA_DIR} ${OPENCXX_SHAREDIR}/examples
	${INSTALL_DATA} ${WRKSRC}/../../sample/* ${OPENCXX_SHAREDIR}/examples/
	${INSTALL_DATA_DIR} ${PREFIX}/include/openc++
	${INSTALL_DATA} ${WRKSRC}/../*.h ${PREFIX}/include/openc++
	${INSTALL_DATA_DIR} ${OPENCXX_SHAREDIR}/doc/html
	${INSTALL_DATA} ${WRKSRC}/../../html/* ${OPENCXX_SHAREDIR}/doc/html
	${INSTALL_DATA} ${WRKSRC}/../../reference.pdf ${OPENCXX_SHAREDIR}/doc

.include "../../devel/boehm-gc/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
