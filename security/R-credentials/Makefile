# $NetBSD: Makefile,v 1.2 2022/05/11 14:22:23 mef Exp $

R_PKGNAME=	credentials
R_PKGVER=	1.3.2
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Tools for Managing SSH and Git Credentials
LICENSE=	mit	# + file LICENSE

DEPENDS+=	R-askpass>=1.1:../../security/R-askpass
DEPENDS+=	R-openssl>=1.3:../../security/R-openssl
DEPENDS+=	R-sys>=2.1:../../sysutils/R-sys
DEPENDS+=	R-jsonlite>=1.7.1:../../textproc/R-jsonlite
DEPENDS+=	R-curl>=4.3:../../www/R-curl

TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
