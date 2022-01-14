# $NetBSD: Makefile,v 1.20 2022/01/14 11:37:24 wiz Exp $

VERS=		0.10.0
#PKGREVISION=	1
DISTNAME=	hg-git-${VERS}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel scm
MASTER_SITES=	https://foss.heptapod.net/mercurial/hg-git/-/archive/${VERS}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://hg-git.github.io/
COMMENT=	Push to and pull from a Git server repository using Mercurial
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-dulwich>=0.9.7:../../devel/py-dulwich

USE_LANGUAGES=	# none

# py-dulwich
PYTHON_VERSIONS_INCOMPATIBLE=	27

EGG_NAME=	${DISTNAME:S/-/_/1}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
