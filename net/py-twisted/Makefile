# $NetBSD: Makefile,v 1.9 2008/04/25 20:39:11 joerg Exp $
#

DISTNAME=		${TWISTED_DISTNAME}
PKGNAME=		${PYPKGPREFIX}-${TWISTED_PKGNAME}
PKGREVISION=		1
CATEGORIES=		net python
MASTER_SITES=		${TWISTED_MASTER_SITES}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.twistedmatrix.com/
COMMENT=		Framework for writing networked applications

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes
PLIST_SUBST+=		PYVERSSUFFIX="-${PYVERSSUFFIX}"
MAKE_ENV+=		PKGSRC="1" PYVERSSUFFIX="-${PYVERSSUFFIX}"

PYTHON_VERSIONS_ACCEPTED=	25 24 23

.include "../../net/py-twisted/Makefile.common"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
