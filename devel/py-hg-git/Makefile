# $NetBSD: Makefile,v 1.11 2019/04/26 13:13:52 maya Exp $

DISTNAME=	0.8.10
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
WRKSRC=		${WRKDIR}/durin42-hg-git-6ef27582bfa5

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	 36 37 # as of 0.8.3
EGG_NAME=	hg_git-${DISTNAME}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
