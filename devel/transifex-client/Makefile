# $NetBSD: Makefile,v 1.12 2018/04/18 19:47:20 kamil Exp $

DISTNAME=	transifex-client-0.13.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=transifex/}

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	https://github.com/transifex/${GITHUB_PROJECT}
COMMENT=	Transifex Command-line Client
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-urllib3>=1.14:../../www/py-urllib3

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
