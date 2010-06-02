# $NetBSD: Makefile,v 1.8 2010/06/02 18:31:41 gls Exp $
#

DISTNAME=		paramiko-1.7.6
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKG_REVISION=	1
CATEGORIES=		security
MASTER_SITES=	http://www.lag.net/paramiko/download/
EXTRACT_SUFX=	.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.lag.net/paramiko/
COMMENT=		SSH2 protocol library
LICENSE=		gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes
REPLACE_PYTHON=	paramiko/rng*.py

do-test:
	(cd ${WRKSRC} && ${PYTHONBIN} test.py)

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../security/py-amkCrypto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
