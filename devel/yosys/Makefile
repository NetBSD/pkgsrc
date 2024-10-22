# $NetBSD: Makefile,v 1.11 2024/10/22 05:31:32 thorpej Exp $

# XXX Yosys changed their release tag format in 0.45 to just a bare
# XXX number, sigh.
YOSYS_VERSION=	0.46
YOSYS_TAG=	${YOSYS_VERSION}
ABC_TAG=	yosys-${YOSYS_VERSION}
ABC_DISTNAME=	abc-${ABC_TAG}
DISTNAME=	yosys-${YOSYS_TAG}
#PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=YosysHQ/}
GITHUB_TAG=	${YOSYS_TAG}
WRKSRC=		${WRKDIR}/yosys-${YOSYS_TAG}
EXTRACT_SUFX=	.tar.gz		# needed early

MAINTAINER=	thorpej@NetBSD.org
HOMEPAGE=	https://github.com/YosysHQ/yosys
COMMENT=	Yosys Open SYnthesis Suite
LICENSE=	isc

DEPENDS+=	graphviz-[0-9]*:../../graphics/graphviz

ONLY_FOR_COMPILER=	clang gcc
USE_LANGUAGES=		c c++

.include "../../mk/bsd.prefs.mk"
.include "../../mk/compiler.mk"

ABC_DISTFILE=	${ABC_DISTNAME}${EXTRACT_SUFX}
DISTFILES=	${DEFAULT_DISTFILES}

DISTFILES+=		${ABC_DISTFILE}
SITES.${ABC_DISTFILE}=	-${MASTER_SITE_GITHUB:=YosysHQ/abc/archive/}${ABC_TAG}${EXTRACT_SUFX}

EXTRACT_DIR.${ABC_DISTFILE}=		${WRKSRC}/abc
EXTRACT_OPTS_TAR.${ABC_DISTFILE}=	--strip-components=1

.if ${CC_VERSION:Mclang*}
YOSYS_COMPILER=	clang
.else
YOSYS_COMPILER=	gcc
.endif

USE_TOOLS+=	bash
USE_TOOLS+=	git
USE_TOOLS+=	gmake
USE_TOOLS+=	bison
USE_TOOLS+=	flex
USE_TOOLS+=	gawk
USE_TOOLS+=	pkg-config

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

REPLACE_BASH+=		misc/yosys-config.in

do-configure:
	cd ${WRKSRC} && ${MAKE_PROGRAM} config-${YOSYS_COMPILER}

.include "../../lang/python/application.mk"
.include "../../lang/python/tool.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
