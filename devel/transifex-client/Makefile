# $NetBSD: Makefile,v 1.16 2019/02/19 16:27:48 taca Exp $

DISTNAME=	transifex-client-0.13.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=transifex/}
GITHUB_PROJECT=	transifex-client

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	https://github.com/transifex/${GITHUB_PROJECT}
COMMENT=	Transifex Command-line Client
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-urllib3>=1.14:../../www/py-urllib3
DEPENDS+=	${PYPKGPREFIX}-six>=1.11:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-requests>=2.19.1:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-python-slugify>=1.2.6:../../devel/py-python-slugify

EXTRACT_USING=	gtar

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} tx tx-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
