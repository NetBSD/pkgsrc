# $NetBSD: Makefile,v 1.1 2016/07/22 00:02:56 mef Exp $

DISTNAME=	gdspy-0.7.1
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_PYPI:=g/gdspy/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/packages/source/g/gdspy/
COMMENT=	Python module for creating GDSII stream files
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy

PYDISTUTILSPKG= yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
