# $NetBSD: Makefile,v 1.4 2004/01/23 15:31:58 recht Exp $
#

DISTNAME=	ZSI-1.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pywebsvcs/}

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://pywebsvcs.sourceforge.net/
COMMENT=	SOAP implementation

USE_BUILDLINK2=	yes
PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

DIST_SUBDIR=	py-ZSI

post-extract:
	${MV} ${WRKSRC}/scripts/wsdl2py \
		${WRKSRC}/scripts/wsdl2py-${PYVERSSUFFIX}

.include "../../lang/python/extension.mk"
.include "../../textproc/py-xml/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
