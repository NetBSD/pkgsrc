# $NetBSD: Makefile,v 1.1 2013/08/21 15:26:56 drochner Exp $

DISTNAME=	v1.1.1
PKGNAME=	${PYPKGPREFIX}-discogs_client-1.1.1
CATEGORIES=	audio
MASTER_SITES=	https://github.com/discogs/discogs_client/archive/
DIST_SUBDIR=	discogs_client

MAINTAINER=	pkgsrc_users@NetBSD.org
HOMEPAGE=	https://github.com/discogs/discogs_client/
COMMENT=	Python Client for the Discogs API
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/discogs_client-1.1.1
USE_LANGUAGES=	# none
EGG_NAME=	discogs_client-1.1.1

DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
