# $NetBSD: Makefile,v 1.7 2018/11/14 10:41:17 adam Exp $

DISTNAME=	whisper-1.1.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/whisper/}

MAINTAINER=	riz@NetBSD.org
HOMEPAGE=	https://github.com/graphite-project/whisper
COMMENT=	Fixed-size database, similar in design to RRD
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=	# none

PYTHON_SELF_CONFLICT=	yes

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
