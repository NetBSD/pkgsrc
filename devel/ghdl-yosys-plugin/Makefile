# $NetBSD: Makefile,v 1.2 2026/04/20 08:21:29 wiz Exp $

DISTNAME=	ghdl-yosys-plugin-0.0.0.20251102
PKGREVISION=	1
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
