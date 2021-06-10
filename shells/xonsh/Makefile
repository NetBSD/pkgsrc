# $NetBSD: Makefile,v 1.7 2021/06/10 07:34:52 adam Exp $

DISTNAME=	xonsh-0.8.8
PKGREVISION=	2
CATEGORIES=	shells python
MASTER_SITES=	${MASTER_SITE_GITHUB:=xonsh/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xon.sh/
COMMENT=	Python-ish, BASHwards-looking shell language and command prompt
LICENSE=	2-clause-bsd

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	${PYPKGPREFIX}-ply-[0-9]*:../../devel/py-ply
DEPENDS+=	${PYPKGPREFIX}-prompt_toolkit-[0-9]*:../../devel/py-prompt_toolkit
DEPENDS+=	${PYPKGPREFIX}-pygments-[0-9]*:../../textproc/py-pygments

PKG_SHELL=	${PREFIX}/bin/xon.sh
PKG_SHELL+=	${PREFIX}/bin/xonsh

SUBST_CLASSES+=		xonsh
SUBST_STAGE.xonsh=	pre-configure
SUBST_FILES.xonsh=	scripts/xon.sh scripts/xonsh scripts/xonsh-cat
SUBST_SED.xonsh=	-e 's,python3,${PYTHONBIN},'

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
