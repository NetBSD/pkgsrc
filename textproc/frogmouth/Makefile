# $NetBSD: Makefile,v 1.1 2024/08/12 10:07:30 wiz Exp $

DISTNAME=	frogmouth-0.9.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PYPI:=f/frogmouth/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Textualize/frogmouth
COMMENT=	Markdown browser for your terminal
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core-[0-9]*:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-textual>=0.43.0:../../comms/py-textual
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.5.0:../../devel/py-typing-extensions
DEPENDS+=	${PYPKGPREFIX}-httpx>=0.24.1:../../www/py-httpx
# XXX
DEPENDS+=	${PYPKGPREFIX}-xdg-base-dirs>=6.0.0:../../devel/py-xdg-base-dirs

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} frogmouth frogmouth-${PYVERSSUFFIX} || ${TRUE}
	find ${DESTDIR} -name *.orig -delete

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
