# $NetBSD: Makefile,v 1.11 2004/03/03 10:13:20 recht Exp $
#

DISTNAME=	SOAPpy-0.11.3
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
.include "../../textproc/py-xml/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
