# $NetBSD: Makefile,v 1.2 2022/01/04 20:53:12 wiz Exp $

DISTNAME=	iso-639-0.4.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=i/iso-639/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/iso-639/
COMMENT=	Library for working with ISO-639 language codes
LICENSE=	gnu-agpl-v3

EGG_NAME=	${DISTNAME:S/-/_/}
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
