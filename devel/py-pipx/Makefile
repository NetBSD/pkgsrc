# $NetBSD: Makefile,v 1.7 2026/10/29 11:45:14 adam Exp $

DISTNAME=	pipx-1.18.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pipx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pipx.pypa.io/
COMMENT=	Install and Run Python Applications in Isolated Environments
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-docutils>=0.21.2:../../textproc/py-docutils
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs>=0.5:../../devel/py-hatch-vcs
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.32.4:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-argcomplete>=3.7.2:../../devel/py-argcomplete
DEPENDS+=	${PYPKGPREFIX}-filelock>=4.2:../../devel/py-filelock
DEPENDS+=	${PYPKGPREFIX}-packaging>=26.3:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-platformdirs>=4.12.2:../../misc/py-platformdirs
DEPENDS+=	${PYPKGPREFIX}-userpath>=1.9.2:../../devel/py-userpath

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	pipx

SUBST_CLASSES+=		mandir
SUBST_STAGE.mandir=	pre-configure
SUBST_MESSAGE.mandir=	Setting correct mandir.
SUBST_FILES.mandir=	pyproject.toml
SUBST_SED.mandir=	-e 's,share/man,${PKGMANDIR},g'

post-install:
	cd ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1 && \
	${MV} pipx.1 pipx-${PYVERSSUFFIX}.1 || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
