# $NetBSD: Makefile,v 1.25 2024/11/11 07:28:10 wiz Exp $

DISTNAME=	hg-git-1.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel scm
MASTER_SITES=	https://foss.heptapod.net/mercurial/hg-git/-/archive/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://hg-git.github.io/
COMMENT=	Push to and pull from a Git server repository using Mercurial
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-dulwich>=0.20.11:../../devel/py-dulwich
DEPENDS+=	${PYPKGPREFIX}-mercurial>=6.1:../../devel/py-mercurial

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
