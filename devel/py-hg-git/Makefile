# $NetBSD: Makefile,v 1.2 2015/07/27 09:34:41 wiz Exp $

DISTNAME=	0.8.1
PKGNAME=	${PYPKGPREFIX}-hg-git-${DISTNAME}
CATEGORIES=	devel scm
MASTER_SITES=	https://bitbucket.org/durin42/hg-git/get/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://hg-git.github.io/
COMMENT=	Push to and pull from a Git server repository using Mercurial
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-dulwich>=0.9.7:../../devel/py-dulwich

DIST_SUBDIR=	hg-git
WRKSRC=		${WRKDIR}/durin42-hg-git-e6489cf3fe8c

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-dulwich
EGG_NAME=	hg_git-${DISTNAME}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
