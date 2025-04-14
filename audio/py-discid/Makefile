# $NetBSD: Makefile,v 1.2 2025/04/14 06:04:53 adam Exp $

DISTNAME=	discid-1.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	audio python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/discid/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://python-discid.readthedocs.io/
COMMENT=	Python binding of libdiscid
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	libdiscid-[0-9]*:../../audio/libdiscid

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
