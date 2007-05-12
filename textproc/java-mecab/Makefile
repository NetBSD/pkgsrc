# $NetBSD: Makefile,v 1.1.1.1 2007/05/12 13:53:46 obache Exp $
#

.include "../../textproc/mecab/Makefile.common"

DISTNAME=	mecab-java-${MECAB_VERSION}
PKGNAME=	java-mecab-${MECAB_VERSION}
CATEGORIES+=	java

COMMENT=	MeCab java module

USE_LANGUAGES=	c++

TEST_TARGET=	test

do-install:
	${INSTALL_LIB} ${WRKSRC:Q}/libMeCab.so ${PREFIX:Q}/lib
	${INSTALL_LIB} ${WRKSRC:Q}/MeCab.jar ${PREFIX:Q}/lib

.include "../../textproc/mecab/buildlink3.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
