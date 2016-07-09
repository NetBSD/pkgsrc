# $NetBSD: Makefile,v 1.2 2016/07/09 13:03:57 wiz Exp $

DISTNAME=	livestreamer-1.12.2
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=chrippa/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://livestreamer.tanuki.se/
COMMENT=	Tool that pipes video streams into a video player
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests

.include "../../lang/python/egg.mk"

.if ${_PYTHON_VERSION} < 30
DEPENDS+=	${PYPKGPREFIX}-singledispatch-[0-9]*:../../devel/py-singledispatch
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-futures-[0-9]*:../../devel/py-futures
.endif

EGG_NAME=	${PKGNAME_NOREV}

REPLACE_PYTHON+= src/livestreamer/packages/flashmedia/flv.py
REPLACE_PYTHON+= src/livestreamer/packages/flashmedia/tag.py
REPLACE_PYTHON+= src/livestreamer/packages/flashmedia/__init__.py
REPLACE_PYTHON+= src/livestreamer/packages/flashmedia/packet.py
REPLACE_PYTHON+= src/livestreamer/packages/flashmedia/error.py
REPLACE_PYTHON+= src/livestreamer/packages/flashmedia/f4v.py
REPLACE_PYTHON+= src/livestreamer/packages/flashmedia/util.py
REPLACE_PYTHON+= src/livestreamer/plugins/tv3cat.py
REPLACE_PYTHON+= src/livestreamer/plugins/tvplayer.py

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
