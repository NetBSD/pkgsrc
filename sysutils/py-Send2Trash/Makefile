# $NetBSD: Makefile,v 1.11 2025/03/05 10:27:09 wiz Exp $

DISTNAME=	Send2Trash-1.8.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=S/Send2Trash/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hsoft/send2trash
COMMENT=	Send file to trash
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=75.8.2:../../devel/py-setuptools

USE_LANGUAGES=	# none

WHEEL_NAME=	${DISTNAME:tl}

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} send2trash send2trash-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
