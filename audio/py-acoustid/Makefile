# $NetBSD: Makefile,v 1.9 2019/04/26 14:12:31 maya Exp $

DISTNAME=	v1.0.0
PKGNAME=	${PYPKGPREFIX}-acoustid-1.0.0
CATEGORIES=	audio
MASTER_SITES=	https://github.com/sampsyo/pyacoustid/archive/
DIST_SUBDIR=	pyacoustid

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sampsyo/pyacoustid
COMMENT=	Audio fingerprinting
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-audioread-[0-9]*:../../audio/py-audioread
DEPENDS+=	chromaprint-[0-9]*:../../audio/chromaprint

WRKSRC=		${WRKDIR}/pyacoustid-1.0.0
USE_LANGUAGES=	# none
EGG_NAME=	pyacoustid-1.0.0
PYTHON_VERSIONS_INCOMPATIBLE=	36 37 # not yet ported as of 1.0.0

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
