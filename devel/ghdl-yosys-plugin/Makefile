# $NetBSD: Makefile,v 1.1 2025/12/25 18:03:55 ryoon Exp $

DISTNAME=	ghdl-yosys-plugin-0.0.0.20251102
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ghdl/}
GITHUB_PROJECT=	ghdl-yosys-plugin
GITHUB_TAG=	ad5be7439eb4331343e26f9199d3678985088fed

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/ghdl/ghdl-yosys-plugin/
COMMENT=	VHDL synthesis based on GHDL and Yosys
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c++

USE_TOOLS+=	gmake

MAKE_FLAGS+=	GHDL=${PREFIX}/bin/ghdl
MAKE_FLAGS+=	YOSYS_CONFIG=${PREFIX}/bin/yosys-config

BUILDLINK_DEPMETHOD.gcc14-gnat=	full
.include "../../lang/gcc14-gnat/buildlink3.mk"
.include "../../cad/ghdl/buildlink3.mk"
.include "../../devel/yosys/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
