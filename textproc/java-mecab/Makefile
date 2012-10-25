# $NetBSD: Makefile,v 1.6 2012/10/25 06:56:01 asau Exp $
#

.include "../../textproc/mecab/Makefile.common"

DISTNAME=	mecab-java-${MECAB_VERSION}
PKGNAME=	java-mecab-${MECAB_VERSION}
CATEGORIES+=	java

COMMENT=	MeCab java module
LICENSE=	gnu-gpl-v2 OR gnu-lgpl-v2.1 OR modified-bsd

USE_LANGUAGES=	c++

TEST_TARGET=	test

INSTALLATION_DIRS+=	lib

do-install:
	${INSTALL_LIB} ${WRKSRC}/libMeCab.so ${DESTDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/MeCab.jar ${DESTDIR}${PREFIX}/lib

BUILDLINK_API_DEPENDS.mecab+=	mecab>=${MECAB_VERSION}

.include "../../textproc/mecab/buildlink3.mk"
.include "../../mk/java-vm.mk"
CXXFLAGS+=	-I${PKG_JAVA_HOME}/include
CXXFLAGS+=	-I${PKG_JAVA_HOME}/include/${LOWER_OPSYS}
.include "../../mk/bsd.pkg.mk"
