# $NetBSD: Makefile,v 1.1 2022/04/23 06:17:06 mef Exp $

R_PKGNAME=	ids
R_PKGVER=	1.0.1

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Generate Random Identifiers
LICENSE=	mit	# + file LICENSE

DEPENDS+=	R-uuid>=1.1.0:../../devel/R-uuid
DEPENDS+=	R-openssl>=1.4.3:../../security/R-openssl

# Package suggested but not available: 'rcorpora'

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
