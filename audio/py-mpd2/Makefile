# $NetBSD: Makefile,v 1.2 2021/12/19 13:18:11 wiz Exp $

DISTNAME=	python-mpd2-1.0.0
PKGNAME=	${PYPKGPREFIX}-mpd2-1.0.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-mpd2/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://musicpd.org/libs/python-mpd2/
COMMENT=	Python mpd client library
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
