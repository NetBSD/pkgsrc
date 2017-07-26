# $NetBSD: Makefile,v 1.11 2017/07/26 17:10:15 adam Exp $

DISTNAME=	Mako-1.0.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=M/Mako/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.makotemplates.org/
COMMENT=	Hyperfast and lightweight templating for the Python platform
LICENSE=	mit

USE_LANGUAGES=		# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} mako-render mako-render${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
