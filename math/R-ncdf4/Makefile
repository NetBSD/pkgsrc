# $NetBSD: Makefile,v 1.2 2021/09/29 19:00:57 adam Exp $

R_PKGNAME=	ncdf4
R_PKGVER=	1.17

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Interface to Unidata netCDF (Version 4 or Earlier) Format Data Files
PKGREVISION=	1
LICENSE=	gnu-gpl-v3

# ./configure: 1833: Syntax error: Bad substitution
USE_TOOLS+=	bash
REPLACE_BASH+=	configure

.include "../../math/R/Makefile.extension"
.include "../../devel/netcdf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
