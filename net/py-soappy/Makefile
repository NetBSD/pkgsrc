# $NetBSD: Makefile,v 1.8 2003/12/24 11:42:02 recht Exp $
#

DISTNAME=	SOAPpy-0.11.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pywebsvcs/}

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://pywebsvcs.sourceforge.net/
COMMENT=	SOAP implementation

DEPENDS=	${PYPKGPREFIX}-fpconst>=0.6.0:../../math/py-fpconst

USE_BUILDLINK2=	YES
PYDISTUTILSPKG=	YES
PY_PATCHPLIST=	YES

PYTHON_VERSIONS_ACCEPTED=	23pth 22pth 21pth

.include "../../lang/python/extension.mk"
.include "../../textproc/pyxml/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
