# $NetBSD: Makefile,v 1.18 2014/12/31 13:57:26 wiz Exp $

DISTNAME=	hg-git-0.4.0
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://hg-git.github.com/
COMMENT=	Git plugin for Mercurial

DEPENDS+=	${PYPKGPREFIX}-dulwich>=0.8.6:../../devel/py-dulwich
DEPENDS+=	mercurial>=1.9.4:../../devel/mercurial

USE_LANGUAGES=	#none
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-dulwich

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
