# $NetBSD: Makefile,v 1.1 2021/11/29 10:20:24 mef Exp $

R_PKGNAME=	whoami
R_PKGVER=	1.3.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Username, Full Name, Email addr. 'GitHub' Username of the Current User
LICENSE=	mit	# + file LICENSE

DEPENDS+=	R-jsonlite>=1.7.1:../../textproc/R-jsonlite
DEPENDS+=	R-httr>=1.4.2:../../www/R-httr

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
