# $NetBSD: Makefile,v 1.11 2018/03/23 15:02:05 taca Exp $

DISTNAME=	${VERS}
PKGNAME=	transifex-client-${VERS}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=transifex/}

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	https://github.com/transifex/${GITHUB_PROJECT}
COMMENT=	Transifex Command-line Client
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-urllib3>=1.14:../../www/py-urllib3

VERS=		0.13.1
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
