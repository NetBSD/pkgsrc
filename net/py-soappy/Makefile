# $NetBSD: Makefile,v 1.18 2005/01/23 20:41:48 recht Exp $
#

DISTNAME=	SOAPpy-0.11.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pywebsvcs/}

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://pywebsvcs.sourceforge.net/
COMMENT=	SOAP implementation

USE_BUILDLINK3=	YES
PYDISTUTILSPKG=	YES
PY_PATCHPLIST=	YES

PYTHON_VERSIONS_ACCEPTED=	24 23 22 21

.include "../../lang/python/extension.mk"
.include "../../math/py-fpconst/buildlink3.mk"
.include "../../textproc/py-xml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
