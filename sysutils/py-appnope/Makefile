# $NetBSD: Makefile,v 1.1 2019/10/21 19:15:52 adam Exp $

DISTNAME=	appnope-0.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/appnope/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/minrk/appnope
COMMENT=	Disable App Nap on macOS
LICENSE=	modified-bsd

ONLY_FOR_PLATFORM=	Darwin-*-*

USE_LANGUAGES=	# none

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
