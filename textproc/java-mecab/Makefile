# $NetBSD: Makefile,v 1.4 2009/12/28 01:01:19 obache Exp $
#

.include "../../textproc/mecab/Makefile.common"

DISTNAME=	mecab-java-${MECAB_VERSION}
PKGNAME=	java-mecab-${MECAB_VERSION}
CATEGORIES+=	java

COMMENT=	MeCab java module
LICENSE=	gnu-gpl-v2 OR gnu-lgpl-v2.1 OR modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

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
.for d in ${PKG_JAVA_HOME}/include/*
.  if exists(${d}/jni_md.h)
CXXFLAGS+=	-I${d}
.  endif
.endfor
.include "../../mk/bsd.pkg.mk"
