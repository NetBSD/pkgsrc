# $NetBSD: Makefile,v 1.9 2010/12/06 22:22:08 gls Exp $
#

DISTNAME=		paramiko-1.7.6
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKG_REVISION=	2
CATEGORIES=		security
MASTER_SITES=	http://pypi.python.org/packages/source/p/paramiko/
EXTRACT_SUFX=	.zip
DIST_SUBDIR=	${DISTNAME}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.lag.net/paramiko/
COMMENT=		SSH2 protocol library
LICENSE=		gnu-lgpl-v2.1

DEPENDS+=   ${PYPKGPREFIX}-crypto-[0-9]*:../../security/py-crypto

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes
REPLACE_PYTHON=	paramiko/rng*.py

do-test:
	(cd ${WRKSRC} && ${PYTHONBIN} test.py)

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
