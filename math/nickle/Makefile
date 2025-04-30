# $NetBSD: Makefile,v 1.35 2025/04/30 11:43:13 wiz Exp $

DISTNAME=	nickle-2.103
CATEGORIES=	math lang
MASTER_SITES=	http://nickle.org/release/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://nickle.org/
COMMENT=	Desk calculator language
LICENSE=	mit

MESON_ARGS+=	-Dlibedit=true

TEST_TARGET=	check

REPLACE_SH+=	bench/runbench.sh

USE_TOOLS+=	pkg-config

.include "../../devel/meson/build.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
