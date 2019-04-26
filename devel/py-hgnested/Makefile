# $NetBSD: Makefile,v 1.11 2019/04/26 13:13:52 maya Exp $

DISTNAME=	hgnested-0.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hgnested/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bitbucket.org/cedk/hgnested
COMMENT=	Mercurial extension to work with nested repositories
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-mercurial>=1.6:../../devel/py-mercurial

PYTHON_VERSIONS_INCOMPATIBLE=	 36 37	# XXX: devel/py-mercurial

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
