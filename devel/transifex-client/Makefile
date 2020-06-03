# $NetBSD: Makefile,v 1.19 2020/06/03 16:43:15 adam Exp $

DISTNAME=	transifex-client-0.13.7
PKGREVISION=	1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=transifex/}
GITHUB_PROJECT=	transifex-client

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	https://github.com/transifex/${GITHUB_PROJECT}
COMMENT=	Transifex Command-line Client
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-urllib3>=1.14.2:../../www/py-urllib3
DEPENDS+=	${PYPKGPREFIX}-six>=1.11:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-requests>=2.19.1:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-slugify>=1.2.6:../../devel/py-slugify

EXTRACT_USING=	bsdtar

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} tx tx-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
