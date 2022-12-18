# $NetBSD: Makefile,v 1.1 2022/12/18 01:44:09 mef Exp $

R_PKGNAME=	jose
R_PKGVER=	1.2.0
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	JavaScript Object Signing and Encryption
LICENSE=	mit	# + file LICENSE

DEPENDS+=	R-openssl>=2.0.5:../../security/R-openssl
DEPENDS+=	R-jsonlite>=1.8.0:../../textproc/R-jsonlite

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
