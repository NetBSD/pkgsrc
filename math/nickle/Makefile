# $NetBSD: Makefile,v 1.37 2025/06/20 14:09:49 nia Exp $

DISTNAME=	nickle-2.103
CATEGORIES=	math lang
MASTER_SITES=	http://nickle.org/release/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://nickle.org/
COMMENT=	Desk calculator language
LICENSE=	mit

TEST_TARGET=	check

REPLACE_SH+=	bench/runbench.sh

USE_TOOLS+=	pkg-config
USE_TOOLS+=	bison flex

# Tests have a tool dependency on bc; meson insists on checking for it.
.if !exists(/usr/bin/bc)
TOOL_DEPENDS+=	bc-[0-9]*:../../math/bc
.endif

.include "../../mk/readline.buildlink3.mk"

.if ${READLINE_TYPE} == "editline"
MESON_ARGS+=	-Dlibedit=true
.else
MESON_ARGS+=	-Dlibedit=false
.endif

.include "../../devel/meson/build.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
