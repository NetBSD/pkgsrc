# $NetBSD: Makefile,v 1.6 2010/02/12 19:43:50 joerg Exp $
#

DISTNAME=		hg-git-0.2.1
EGG_NAME=		hg_git-0.2.1
CATEGORIES=		devel python
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://hg-git.github.com
COMMENT=		Git plugin for Mercurial

DEPENDS+=	${PYPKGPREFIX}-dulwich-[0-9]*:../../devel/py-dulwich
DEPENDS+=	mercurial>=1.3.1:../../devel/mercurial


PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
