# $NetBSD: Makefile,v 1.7 2024/12/28 21:30:15 adam Exp $

DISTNAME=	musicbrainzngs-0.7.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/ngs/-ngs/}
CATEGORIES=	audio net python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/musicbrainzngs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/alastair/python-musicbrainzngs
COMMENT=	Python bindings for Musicbrainz NGS service
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
