# $NetBSD: Makefile,v 1.6 2015/07/01 13:54:22 wiz Exp $

DISTNAME=		pyasn1-0.1.8
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
