# $NetBSD: Makefile,v 1.7 2003/09/14 16:43:54 recht Exp $
#

DISTNAME=	SOAPpy-0.10.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pywebsvcs/}

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://pywebsvcs.sourceforge.net/
COMMENT=	SOAP implementation

USE_BUILDLINK2=	YES

PYDISTUTILSPKG=	YES
PY_PATCHPLIST=	YES

PYTHON_VERSIONS_ACCEPTED=	23pth 22pth 21pth

.include "../../lang/python/extension.mk"
.include "../../textproc/pyxml/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
