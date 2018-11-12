# $NetBSD: Makefile,v 1.56 2018/11/12 03:51:51 ryoon Exp $

DISTNAME=	cppcheck-1.76.1
PKGREVISION=	16
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cppcheck/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://cppcheck.sourceforge.net/
COMMENT=	Tool for static C/C++ code analysis
LICENSE=	gnu-gpl-v3

BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl
DEPENDS+=	${PYPKGPREFIX}-pygments-[0-9]*:../../textproc/py-pygments

USE_LANGUAGES=		c c++0x
USE_TOOLS+=		gmake

BUILD_TARGET=		all man
BUILD_MAKE_FLAGS+=	DB2MAN=${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl
# tell cppcheck where its config is
MAKE_FLAGS+=		CFGDIR=${PREFIX}/share/cppcheck/cfg
# rules support (needs pcre)
MAKE_FLAGS+=		HAVE_RULES=yes

# use pkgsrc tinyxml2 instead of included copy
MAKE_FLAGS+=		TINYXML=
MAKE_FLAGS+=		INCLUDE_FOR_LIB="-Ilib -Iexternals/simplecpp"
MAKE_FLAGS+=		INCLUDE_FOR_CLI="-Ilib -Iexternals/simplecpp"
MAKE_FLAGS+=		INCLUDE_FOR_TEST="-Ilib -Icli -Iexternals/simplecpp"
CPPFLAGS+=		-I${BUILDLINK_PREFIX.tinyxml2}/include
LDFLAGS+=		${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.tinyxml2}/lib -L${BUILDLINK_PREFIX.tinyxml2}/lib -ltinyxml2

.include "../../mk/compiler.mk"
.if !empty(CC_VERSION:Mgcc-4.[0-5]*) || !empty(CC_VERSION:Mgcc-3.*)
CXXFLAGS+= -include lib/cxx11emu.h
.endif

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

REPLACE_PYTHON+=	htmlreport/cppcheck-htmlreport
REPLACE_PYTHON+=	addons/y2038/y2038.py

.include "options.mk"

.PHONY: man-install
post-install: man-install
man-install:
	${INSTALL_DATA} ${WRKSRC}/cppcheck.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/python/application.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../textproc/tinyxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
