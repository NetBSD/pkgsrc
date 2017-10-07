# $NetBSD: Makefile,v 1.2 2017/10/07 20:45:31 joerg Exp $

DISTNAME=	buildbot-worker-0.9.11
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel net python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/buildbot-worker/}

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://buildbot.net/
COMMENT=	Worker for the buildbot CI system
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-future-[0-9]*:../../devel/py-future
DEPENDS+=	${PYPKGPREFIX}-twisted>=14.0.1:../../net/py-twisted

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
