# $NetBSD: Makefile,v 1.24 2008/06/12 02:14:42 joerg Exp $
#

DISTNAME=	SOAPpy-0.11.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pywebsvcs/}

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://pywebsvcs.sourceforge.net/
COMMENT=	SOAP implementation

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	YES
PY_PATCHPLIST=	YES

.include "../../lang/python/extension.mk"
.include "../../math/py-fpconst/buildlink3.mk"
.include "../../textproc/py-xml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
