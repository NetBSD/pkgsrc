# $NetBSD: Makefile,v 1.23 2022/01/04 20:53:50 wiz Exp $

DISTNAME=	transifex-client-0.14.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=transifex/}
GITHUB_PROJECT=	transifex-client

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	https://github.com/transifex/${GITHUB_PROJECT}
COMMENT=	Transifex Command-line Client
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-urllib3>=1.24.2:../../www/py-urllib3
DEPENDS+=	${PYPKGPREFIX}-six>=1.11:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-requests>=2.19.1:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-slugify>=1.2.6:../../devel/py-slugify
DEPENDS+=	${PYPKGPREFIX}-gitpython>=3.0.0:../../devel/py-gitpython

EXTRACT_USING=	bsdtar

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} tx tx-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
