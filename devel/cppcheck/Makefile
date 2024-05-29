# $NetBSD: Makefile,v 1.103 2024/05/29 16:31:59 adam Exp $

DISTNAME=	cppcheck-2.8
PKGREVISION=	14
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cppcheck/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://cppcheck.sourceforge.net/
COMMENT=	Tool for static C/C++ code analysis
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
TOOL_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl
DEPENDS+=	${PYPKGPREFIX}-pygments-[0-9]*:../../textproc/py-pygments

USE_LANGUAGES=		c c++0x
USE_TOOLS+=		gmake
#USE_CMAKE=		yes

BUILD_TARGET=		all man
BUILD_MAKE_FLAGS+=	DB2MAN=${PREFIX}/share/xsl/docbook/manpages/docbook.xsl
# tell cppcheck where its CPP files are
MAKE_FLAGS+=		FILESDIR=${PREFIX}/share/cppcheck
# rules support (needs pcre)
MAKE_FLAGS+=		HAVE_RULES=yes
MAKE_FLAGS+=		USE_Z3=yes
#CMAKE_ARGS+=		-DBUILD_TESTS=ON
#CMAKE_ARGS+=		-DHAVE_RULES=ON
#CMAKE_ARGS+=		-DUSE_Z3=ON

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../mk/compiler.mk"

.if ${CC_VERSION:Mgcc-4.[0-5]*} || ${CC_VERSION:Mgcc-3.*}
CXXFLAGS+=		-include lib/cxx11emu.h
.endif

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

REPLACE_PYTHON+=	htmlreport/cppcheck-htmlreport

TEST_TARGET=		test

.include "options.mk"

.PHONY: man-install
post-install: man-install
man-install:
	${INSTALL_DATA} ${WRKSRC}/cppcheck.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/pcre/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../math/z3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
