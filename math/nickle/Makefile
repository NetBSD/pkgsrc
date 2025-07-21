# $NetBSD: Makefile,v 1.38 2025/07/21 09:39:12 jperkin Exp $

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

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "../../mk/bsd.prefs.mk"

# Tests have a tool dependency on bc; meson insists on checking for it.
# Also avoid native bc on illumos due to https://www.illumos.org/issues/17511
.if !exists(/usr/bin/bc) || ${OPSYS} == "SunOS"
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
