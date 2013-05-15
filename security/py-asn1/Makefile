# $NetBSD: Makefile,v 1.5 2013/05/15 22:25:22 wiz Exp $

DISTNAME=		pyasn1-0.1.7
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pyasn1/}

MAINTAINER=		tonnerre@NetBSD.org
HOMEPAGE=		http://pyasn1.sourceforge.net/
COMMENT=		ITU Abstract Syntax Notification for Python
LICENSE=		2-clause-bsd

PYDISTUTILSPKG=		yes
PYSETUP=		setup.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
