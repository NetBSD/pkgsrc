# $NetBSD: Makefile,v 1.5 2014/10/17 16:01:15 drochner Exp $

DISTNAME=	mutagen-1.25.1
PKGNAME=	mutagen-tools-1.25.1
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
