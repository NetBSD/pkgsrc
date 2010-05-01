# $NetBSD: Makefile,v 1.3 2010/05/01 17:23:36 tonnerre Exp $
#

DISTNAME=		pyasn1-0.0.11a
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pyasn1/}

MAINTAINER=		tonnerre@NetBSD.org
HOMEPAGE=		http://pyasn1.sourceforge.net/
COMMENT=		ITU Abstract Syntax Notification for Python

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=		yes
PYSETUP=		setup.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
