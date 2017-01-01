# $NetBSD: Makefile,v 1.34 2017/01/01 14:43:52 wiz Exp $

DISTNAME=	SOAPpy-0.11.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pywebsvcs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pywebsvcs.sourceforge.net/
COMMENT=	SOAP implementation

DEPENDS+=	${PYPKGPREFIX}-fpconst>=0.6.0:../../math/py-fpconst
DEPENDS+=	${PYPKGPREFIX}-xml>=0.8.3:../../textproc/py-xml

USE_LANGUAGES=	# empty

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-xml

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
