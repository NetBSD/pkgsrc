# $NetBSD: Makefile,v 1.67 2026/07/17 07:23:08 adam Exp $

DISTNAME=	roundup-2.6.0
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/roundup/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.roundup-tracker.org/
COMMENT=	Issue tracking system with command-line, web and email clients
LICENSE=	mit AND zpl-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	frontends/roundup.cgi

SUBST_CLASSES+=		manpath
SUBST_STAGE.manpath=	pre-configure
SUBST_MESSAGE.manpath=	Fixing manpath.
SUBST_FILES.manpath=	setup.py
SUBST_SED.manpath=	-e 's,share/man/man1,${PKGMANDIR}/man1,g'

# as of 2.5.0
# 1 failed, 1268 passed, 1119 skipped, 2 warnings

pre-configure:
	${MV} ${WRKSRC}/share/man ${WRKSRC}/man

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
