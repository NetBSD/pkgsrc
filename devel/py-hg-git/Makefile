# $NetBSD: Makefile,v 1.22 2023/06/26 11:38:37 wiz Exp $

DISTNAME=	hg-git-1.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel scm
MASTER_SITES=	https://foss.heptapod.net/mercurial/hg-git/-/archive/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://hg-git.github.io/
COMMENT=	Push to and pull from a Git server repository using Mercurial
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-dulwich>=0.9.7:../../devel/py-dulwich
DEPENDS+=	${PYPKGPREFIX}-mercurial-[0-9]*:../../devel/py-mercurial

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

EGG_NAME=	${DISTNAME:S/-/_/1}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
