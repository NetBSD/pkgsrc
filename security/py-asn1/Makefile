# $NetBSD: Makefile,v 1.1.1.1 2008/10/22 16:33:55 tonnerre Exp $
#

DISTNAME=		pyasn1-0.0.8a
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pyasn1/}

MAINTAINER=		tonnerre@NetBSD.org
HOMEPAGE=		http://pyasn1.sourceforge.net/
COMMENT=		ITU Abstract Syntax Notification for Python

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=		yes
#PYBINMODULE=		yes
PYSETUP=		setup.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
