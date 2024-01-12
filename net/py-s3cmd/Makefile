# $NetBSD: Makefile,v 1.26 2024/01/12 05:32:52 adam Exp $

DISTNAME=	s3cmd-2.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/s3cmd/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://s3tools.org/s3cmd
COMMENT=	Command line tool for managing Amazon S3 and CloudFront services
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-magic-[0-9]*:../../sysutils/py-magic

MAKE_ENV+=	S3CMD_INSTPATH_MAN=${PKGMANDIR}

PYTHON_SELF_CONFLICT=		yes
PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
