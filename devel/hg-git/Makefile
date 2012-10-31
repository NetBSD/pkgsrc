# $NetBSD: Makefile,v 1.13 2012/10/31 11:17:05 asau Exp $
#

DISTNAME=		hg-git-0.3.3
#PKGREVISION=		1
EGG_NAME=		hg_git-0.3.3
CATEGORIES=		devel python
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://hg-git.github.com
COMMENT=		Git plugin for Mercurial

DEPENDS+=	${PYPKGPREFIX}-dulwich>=0.8.0:../../devel/py-dulwich
DEPENDS+=	mercurial>=1.7.0:../../devel/mercurial

USE_LANGUAGES=	#none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
