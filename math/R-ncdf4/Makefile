# $NetBSD: Makefile,v 1.8 2023/11/08 13:20:01 wiz Exp $

R_PKGNAME=	ncdf4
R_PKGVER=	1.21

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Interface to Unidata netCDF (Version 4 or Earlier) Format Data Files
PKGREVISION=	2
LICENSE=	gnu-gpl-v3

# ./configure: 1833: Syntax error: Bad substitution
USE_TOOLS+=	bash
REPLACE_BASH+=	configure

.include "../../math/R/Makefile.extension"
.include "../../devel/netcdf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
