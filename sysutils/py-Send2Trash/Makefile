# $NetBSD: Makefile,v 1.13 2026/01/03 10:29:29 adam Exp $

DISTNAME=	send2trash-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/send2t/Send2T/}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=S/Send2Trash/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hsoft/send2trash
COMMENT=	Send file to trash
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} send2trash send2trash-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
