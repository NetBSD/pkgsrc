# $NetBSD: Makefile,v 1.20 2006/01/24 07:32:31 wiz Exp $
#

DISTNAME=	SOAPpy-0.11.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pywebsvcs/}

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://pywebsvcs.sourceforge.net/
COMMENT=	SOAP implementation

PYDISTUTILSPKG=	YES
PY_PATCHPLIST=	YES

PYTHON_VERSIONS_ACCEPTED=	24 23 22 21

.include "../../lang/python/extension.mk"
.include "../../math/py-fpconst/buildlink3.mk"
.include "../../textproc/py-xml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
