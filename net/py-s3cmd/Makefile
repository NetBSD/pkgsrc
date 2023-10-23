# $NetBSD: Makefile,v 1.25 2023/10/23 06:37:50 wiz Exp $

DISTNAME=	s3cmd-2.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/s3cmd/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://s3tools.org/s3cmd
COMMENT=	Command line tool for managing Amazon S3 and CloudFront services
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-magic-[0-9]*:../../sysutils/py-magic

MAKE_ENV+=	S3CMD_INSTPATH_MAN=${PKGMANDIR}

PYTHON_SELF_CONFLICT=		yes
PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
