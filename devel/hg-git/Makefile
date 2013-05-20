# $NetBSD: Makefile,v 1.15 2013/05/20 08:18:55 ryoon Exp $
#

DISTNAME=	hg-git-0.4.0
EGG_NAME=	${DISTNAME:S/hg-/hg_/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://hg-git.github.com/
COMMENT=	Git plugin for Mercurial

DEPENDS+=	${PYPKGPREFIX}-dulwich>=0.8.6:../../devel/py-dulwich
DEPENDS+=	mercurial>=1.9.4:../../devel/mercurial

USE_LANGUAGES=	#none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
