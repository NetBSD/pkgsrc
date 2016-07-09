# $NetBSD: Makefile,v 1.8 2016/07/09 13:03:30 wiz Exp $

DISTNAME=	mutagen-1.27
PKGNAME=	mutagen-tools-1.27
CATEGORIES=	audio
MASTER_SITES=	https://bitbucket.org/lazka/mutagen/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bitbucket.org/lazka/mutagen
COMMENT=	Audio metadata handling for Python
LICENSE=	gnu-gpl-v2

DEPENDS+= ${PYPKGPREFIX}-mutagen-[0-9]*:../../audio/py-mutagen

USE_LANGUAGES=	# none
PY_NO_EGG=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # string type problems

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
