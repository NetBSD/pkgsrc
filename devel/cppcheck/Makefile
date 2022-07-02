# $NetBSD: Makefile,v 1.85 2022/07/02 16:53:10 ryoon Exp $

DISTNAME=	cppcheck-2.1
PKGREVISION=	14
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cppcheck/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://cppcheck.sourceforge.net/
COMMENT=	Tool for static C/C++ code analysis
LICENSE=	gnu-gpl-v3

BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

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

.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:Mgcc-4.[0-5]*) || !empty(CC_VERSION:Mgcc-3.*)
CXXFLAGS+=		-include lib/cxx11emu.h
.endif

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

REPLACE_PYTHON+=	htmlreport/cppcheck-htmlreport

TEST_TARGET=		test

PYTHON_VERSIONED_DEPENDENCIES=	pygments

.include "options.mk"

.PHONY: man-install
post-install: man-install
man-install:
	${INSTALL_DATA} ${WRKSRC}/cppcheck.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/pcre/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../math/z3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
