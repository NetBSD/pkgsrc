# $NetBSD: Makefile,v 1.18 2012/10/23 17:19:04 asau Exp $
#

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

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX:Q}

post-extract:
	${MV} ${WRKSRC}/scripts/wsdl2py \
		${WRKSRC}/scripts/wsdl2py${PYVERSSUFFIX}
	${MV} ${WRKSRC}/scripts/wsdl2dispatch \
		${WRKSRC}/scripts/wsdl2dispatch${PYVERSSUFFIX}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
