# $NetBSD: Makefile,v 1.11 2019/04/26 14:12:31 maya Exp $

DISTNAME=	eyeD3-0.7.11
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_PYPI:=e/eyeD3/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://eyed3.nicfit.net/
COMMENT=	Python tool for working with audio files (in particular, mp3)
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=			# none
PYTHON_VERSIONS_INCOMPATIBLE=	36 37 # not yet ported as of 0.7.11
REPLACE_SH+=			bin/eyeD3

SUBST_CLASSES+=		python
SUBST_STAGE.python=	post-configure
SUBST_MESSAGE.python=	Fixing path to python executable.
SUBST_FILES.python+=	bin/eyeD3
SUBST_SED.python+=	-e "s,python,${PYTHONBIN},"

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
