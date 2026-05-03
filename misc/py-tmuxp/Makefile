# $NetBSD: Makefile,v 1.1 2026/05/03 20:34:45 kim Exp $

DISTNAME=	tmuxp-${VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_GITHUB:=tmux-python/}
GITHUB_PROJECT=	tmuxp
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://tmuxp.git-pull.com/
COMMENT=	Session manager for tmux
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-libtmux>=0.55:../../misc/py-libtmux

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} tmuxp tmuxp-${PYVERSSUFFIX} || \
	${TRUE}

.include "version.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
