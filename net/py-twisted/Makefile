# $NetBSD: Makefile,v 1.3 2004/12/23 21:54:25 darcy Exp $
#

DISTNAME=		${TWISTED_DISTNAME}
PKGNAME=		${PYPKGPREFIX}-${TWISTED_PKGNAME}
CATEGORIES=		net python
MASTER_SITES=		${TWISTED_MASTER_SITES}

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.twistedmatrix.com/
COMMENT=		Framework for writing networked applications

USE_BUILDLINK3=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes
PLIST_SUBST+=		PYVERSSUFFIX="-${PYVERSSUFFIX}"
MAKE_ENV+=		PKGSRC="1" PYVERSSUFFIX="-${PYVERSSUFFIX}"

PYTHON_VERSIONS_ACCEPTED=	24pth 24 23pth 23 22pth 22

.include "../../net/py-twisted/Makefile.common"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
