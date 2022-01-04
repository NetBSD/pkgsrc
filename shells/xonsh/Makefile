# $NetBSD: Makefile,v 1.9 2022/01/04 20:54:46 wiz Exp $

DISTNAME=	xonsh-0.10.1
PKGREVISION=	1
CATEGORIES=	shells python
MASTER_SITES=	${MASTER_SITE_GITHUB:=xonsh/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xon.sh/
COMMENT=	Python-ish, BASHwards-looking shell language and command prompt
LICENSE=	2-clause-bsd

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Linux"
DEPENDS+=	${PYPKGPREFIX}-distro-[0-9]*:../../devel/py-distro
.endif
DEPENDS+=	${PYPKGPREFIX}-prompt_toolkit-[0-9]*:../../devel/py-prompt_toolkit
DEPENDS+=	${PYPKGPREFIX}-pyperclip-[0-9]*:../../x11/py-pyperclip
DEPENDS+=	${PYPKGPREFIX}-pygments-[0-9]*:../../textproc/py-pygments

PKG_SHELL=	${PREFIX}/bin/xon.sh
PKG_SHELL+=	${PREFIX}/bin/xonsh

SUBST_CLASSES+=		xonsh
SUBST_STAGE.xonsh=	pre-configure
SUBST_FILES.xonsh=	scripts/xon.sh
SUBST_SED.xonsh=	-e 's,python3,${PYTHONBIN},'

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
