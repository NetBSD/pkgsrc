# $NetBSD: Makefile,v 1.13 2018/09/23 18:23:22 taca Exp $

DISTNAME=	transifex-client-0.13.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=transifex/}

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	https://github.com/transifex/${GITHUB_PROJECT}
COMMENT=	Transifex Command-line Client
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-urllib3>=1.14:../../www/py-urllib3
DEPENDS+=	${PYPKGPREFIX}-six>=1.11:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-requests>=2.19:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-python-slugify>=1.2.5:../../devel/py-python-slugify

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
