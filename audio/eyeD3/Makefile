# $NetBSD: Makefile,v 1.6 2017/02/08 14:21:26 wiz Exp $

DISTNAME=	eyeD3-0.7.10
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_PYPI:=e/eyeD3/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://eyed3.nicfit.net/
COMMENT=	Python tool for working with audio files (in particular, mp3)
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # not yet ported as of 0.7.5
REPLACE_SH+=		bin/eyeD3

SUBST_CLASSES+=		python
SUBST_SED.python+=	-e "s,python,${PYTHONBIN},"
SUBST_MESSAGE.python=	Fixing path to python executable.
SUBST_FILES.python+=	bin/eyeD3
SUBST_STAGE.python=	post-configure

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
