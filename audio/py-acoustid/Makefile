# $NetBSD: Makefile,v 1.1 2013/04/02 10:44:41 drochner Exp $
#

DISTNAME=	v1.0.0
PKGNAME=	${PYPKGPREFIX}-acoustid-1.0.0
CATEGORIES=	audio
MASTER_SITES=	https://github.com/sampsyo/pyacoustid/archive/
DIST_SUBDIR=	pyacoustid

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sampsyo/pyacoustid
COMMENT=	Audio fingerprinting
LICENSE=	mit

WRKSRC=		${WRKDIR}/pyacoustid-1.0.0
USE_LANGUAGES=	# none
EGG_NAME=	pyacoustid-1.0.0

DEPENDS+=	${PYPKGPREFIX}-audioread-[0-9]*:../../audio/py-audioread
DEPENDS+=	chromaprint-[0-9]*:../../audio/chromaprint

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
