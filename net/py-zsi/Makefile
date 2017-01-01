# $NetBSD: Makefile,v 1.24 2017/01/01 14:43:53 wiz Exp $

DISTNAME=	ZSI-2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pywebsvcs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pywebsvcs.sourceforge.net/
COMMENT=	SOAP implementation

DEPENDS+=	${PYPKGPREFIX}-xml>=0.8.3:../../textproc/py-xml

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-xml

post-extract:
	${MV} ${WRKSRC}/scripts/wsdl2py \
		${WRKSRC}/scripts/wsdl2py${PYVERSSUFFIX}
	${MV} ${WRKSRC}/scripts/wsdl2dispatch \
		${WRKSRC}/scripts/wsdl2dispatch${PYVERSSUFFIX}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
