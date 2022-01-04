# $NetBSD: Makefile,v 1.9 2022/01/04 20:53:22 wiz Exp $

TRYTON_MODULE_NAME=	proteus
PKGREVISION= 2
.include "../../devel/py-trytond/Makefile.common"
CATEGORIES=	devel python

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tryton.org/
COMMENT=	Library to access Tryton's models like a client
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-python-sql-[0-9]*:../../databases/py-python-sql
DEPENDS+=	${PYPKGPREFIX}-trytond-[0-9]*:../../devel/py-trytond

USE_LANGUAGES=	# none

.include "options.mk"

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
