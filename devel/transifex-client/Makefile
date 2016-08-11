# $NetBSD: Makefile,v 1.9 2016/08/11 14:49:01 taca Exp $

DISTNAME=	${VERS}
PKGNAME=	transifex-client-${VERS}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=transifex/}

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	https://github.com/transifex/${GITHUB_PROJECT}
COMMENT=	Transifex Command-line Client
LICENSE=	gnu-gpl-v2

DEPENDS+= ${PYPKGPREFIX}-urllib3>=1.14:../../www/py-urllib3

VERS=		0.12.1
WRKSRC=		${WRKDIR}/${PKGNAME}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
