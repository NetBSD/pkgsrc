# $NetBSD: Makefile,v 1.4 2009/11/04 20:54:08 joerg Exp $
#

DISTNAME=		hg-git-0.1.0pre416
PKGREVISION=		1
EGG_NAME=		hg_git-0.1.0
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
