# $NetBSD: Makefile,v 1.2 2022/01/04 20:54:23 wiz Exp $

DISTNAME=	mpegdash-0.1.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	multimedia python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mpegdash/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/caststack/python-mpegdash
COMMENT=	MPEG-DASH MPD(Media Presentation Description) Parser
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-future-[0-9]*:../../devel/py-future

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
