# $NetBSD: Makefile,v 1.15 2004/07/22 09:16:03 recht Exp $
#

DISTNAME=	SOAPpy-0.11.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pywebsvcs/}

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://pywebsvcs.sourceforge.net/
COMMENT=	SOAP implementation

DEPENDS=	${PYPKGPREFIX}-fpconst>=0.6.0:../../math/py-fpconst

USE_BUILDLINK3=	YES
PYDISTUTILSPKG=	YES
PY_PATCHPLIST=	YES

PYTHON_VERSIONS_ACCEPTED=	23pth 22pth 21pth

.include "../../lang/python/extension.mk"
.include "../../textproc/py-xml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
