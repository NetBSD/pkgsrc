# $NetBSD: Makefile,v 1.19 2017/06/20 12:38:42 adam Exp $

DISTNAME=	mutagen-1.38
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mutagen/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/quodlibet/mutagen
COMMENT=	Audio metadata handling for Python
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none

SUBST_CLASSES+=		manpath
SUBST_STAGE.manpath=	pre-configure
SUBST_MESSAGE.manpath=	Fixing man paths.
SUBST_FILES.manpath=	setup.py
SUBST_SED.manpath=	-e 's,share/man,${PKGMANDIR},'

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
