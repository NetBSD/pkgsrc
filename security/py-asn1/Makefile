# $NetBSD: Makefile,v 1.8 2017/04/08 11:25:11 adam Exp $

DISTNAME=	pyasn1-0.2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyasn1/}

MAINTAINER=	tonnerre@NetBSD.org
HOMEPAGE=	http://pyasn1.sourceforge.net/
COMMENT=	ITU Abstract Syntax Notification for Python
LICENSE=	2-clause-bsd

PYDISTUTILSPKG=		yes
PYSETUP=		setup.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
