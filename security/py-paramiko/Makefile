# $NetBSD: Makefile,v 1.6 2008/06/12 02:14:45 joerg Exp $
#

DISTNAME=		paramiko-1.7.3
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		security
MASTER_SITES=		http://www.lag.net/paramiko/download/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.lag.net/paramiko/
COMMENT=		SSH2 protocol library

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=		yes

do-test:
	(cd ${WRKSRC} && ${PYTHONBIN} test.py)

.include "../../lang/python/extension.mk"
.include "../../security/py-amkCrypto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
