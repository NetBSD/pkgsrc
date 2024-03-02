# $NetBSD: Makefile,v 1.1 2024/03/02 02:03:37 thorpej Exp $

YOSYS_VERSION=	0.38
YOSYS_TAG=	yosys-${YOSYS_VERSION}
ABC_DISTNAME=	abc-${YOSYS_TAG}
DISTNAME=	${YOSYS_TAG}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=YosysHQ/}
GITHUB_TAG=	${YOSYS_TAG}
WRKSRC=		${WRKDIR}/yosys-${YOSYS_TAG}
EXTRACT_SUFX=	.tar.gz		# needed early

MAINTAINER=	thorpej@NetBSD.org
HOMEPAGE=	https://github.com/YosysHQ/yosys
COMMENT=	Yosys Open SYnthesis Suite
LICENSE=	isc

ONLY_FOR_COMPILER=	clang gcc
USE_LANGUAGES=		c c++

.include "../../mk/bsd.prefs.mk"
.include "../../mk/compiler.mk"

ABC_DISTFILE=	${ABC_DISTNAME}${EXTRACT_SUFX}
DISTFILES=	${DEFAULT_DISTFILES}

DISTFILES+=		${ABC_DISTFILE}
SITES.${ABC_DISTFILE}=	-${MASTER_SITE_GITHUB:=YosysHQ/abc/archive/}${GITHUB_TAG}${EXTRACT_SUFX}

EXTRACT_DIR.${ABC_DISTFILE}=		${WRKSRC}/abc
EXTRACT_OPTS_TAR.${ABC_DISTFILE}=	--strip-components=1

.if !empty(CC_VERSION:Mclang*)
YOSYS_COMPILER=	clang
.else
YOSYS_COMPILER=	gcc
.endif

USE_TOOLS+=	gmake
USE_TOOLS+=	bison
USE_TOOLS+=	flex
USE_TOOLS+=	gawk

# The Apple developer tools include git, so we don't need to
# depend on it explicitly in that case.
.if ${OPSYS} != "Darwin"
TOOL_DEPENDS+=	git-base>=2.39.3:../../devel/git-base
.endif

REPLACE_PYTHON+=	backends/smt2/*.py
REPLACE_PYTHON+=	docs/source/*.py
REPLACE_PYTHON+=	passes/pmgen/*.py
REPLACE_PYTHON+=	techlibs/common/*.py
REPLACE_PYTHON+=	techlibs/gatemate/*.py
REPLACE_PYTHON+=	techlibs/gowin/*.py
REPLACE_PYTHON+=	techlibs/lattice/*.py
REPLACE_PYTHON+=	techlibs/nexus/*.py
REPLACE_PYTHON+=	techlibs/xilinx/*.py
REPLACE_PYTHON+=	tests/bram/*.py
REPLACE_PYTHON+=	tests/fsm/*.py
REPLACE_PYTHON+=	tests/opt_share/*.py
REPLACE_PYTHON+=	tests/realmath/*.py
REPLACE_PYTHON+=	tests/share/*.py
REPLACE_PYTHON+=	tests/tools/*.py

do-configure:
	cd ${WRKSRC} && ${MAKE_PROGRAM} config-${YOSYS_COMPILER}

.include "../../lang/python/application.mk"
.include "../../lang/python/tool.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/pkgconf/buildlink3.mk"
.include "../../graphics/graphviz/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
