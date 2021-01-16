# $NetBSD: Makefile,v 1.15 2021/01/16 15:15:30 maya Exp $

PKGVERSION=	0.9.0
DISTNAME=	hg-git-${PKGVERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel scm
MASTER_SITES=	https://foss.heptapod.net/mercurial/hg-git/-/archive/${PKGVERSION}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://hg-git.github.io/
COMMENT=	Push to and pull from a Git server repository using Mercurial
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-dulwich>=0.9.7:../../devel/py-dulwich

USE_LANGUAGES=	# none

EGG_NAME=	hg_git-${DISTNAME}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
