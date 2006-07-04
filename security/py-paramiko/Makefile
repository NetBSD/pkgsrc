# $NetBSD: Makefile,v 1.1.1.1 2006/07/04 15:35:54 drochner Exp $
#

DISTNAME=		paramiko-1.6
PKGNAME=		${PYPKGPREFIX}-paramiko-1.6
CATEGORIES=		security
MASTER_SITES=		http://www.lag.net/paramiko/download/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.lag.net/paramiko/
COMMENT=		SSH2 protocol library

PYDISTUTILSPKG=		yes
PYTHON_VERSIONS_ACCEPTED= 23 24 22

.include "../../lang/python/extension.mk"
.include "../../security/py-amkCrypto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
