# $NetBSD: Makefile,v 1.4 2008/04/25 20:39:12 joerg Exp $
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

.include "../../lang/python/extension.mk"
.include "../../security/py-amkCrypto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
