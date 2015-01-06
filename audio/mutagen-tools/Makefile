# $NetBSD: Makefile,v 1.6 2015/01/06 19:53:14 drochner Exp $

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
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # string type problems

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
