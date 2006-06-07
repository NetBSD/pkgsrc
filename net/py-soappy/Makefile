# $NetBSD: Makefile,v 1.22 2006/06/07 12:52:24 joerg Exp $
#

DISTNAME=	SOAPpy-0.11.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pywebsvcs/}

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://pywebsvcs.sourceforge.net/
COMMENT=	SOAP implementation

PYDISTUTILSPKG=	YES
PY_PATCHPLIST=	YES

PYTHON_VERSIONS_ACCEPTED=	24 23 22

.include "../../lang/python/extension.mk"
.include "../../math/py-fpconst/buildlink3.mk"
.include "../../textproc/py-xml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
