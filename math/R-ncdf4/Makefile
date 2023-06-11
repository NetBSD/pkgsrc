# $NetBSD: Makefile,v 1.6 2023/06/11 03:01:14 mef Exp $

R_PKGNAME=	ncdf4
R_PKGVER=	1.21

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Interface to Unidata netCDF (Version 4 or Earlier) Format Data Files
LICENSE=	gnu-gpl-v3

# ./configure: 1833: Syntax error: Bad substitution
USE_TOOLS+=	bash
REPLACE_BASH+=	configure

.include "../../math/R/Makefile.extension"
.include "../../devel/netcdf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
