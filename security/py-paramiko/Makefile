# $NetBSD: Makefile,v 1.3 2007/12/14 13:35:04 bjs Exp $
#

DISTNAME=		paramiko-1.7.1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		security
MASTER_SITES=		http://www.lag.net/paramiko/download/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.lag.net/paramiko/
COMMENT=		SSH2 protocol library

PYDISTUTILSPKG=		yes
PYTHON_VERSIONS_ACCEPTED= 23 24

.include "../../lang/python/extension.mk"
.include "../../security/py-amkCrypto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
