# $NetBSD: Makefile,v 1.3 2008/01/25 04:31:55 dsainty Exp $
#

DISTNAME=	youtube-dl
PKGNAME=	youtube-dl-20080124
CATEGORIES=	net
MASTER_SITES=	http://www.arrakis.es/~rggi3/youtube-dl/
EXTRACT_SUFX=	# none

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.arrakis.es/~rggi3/youtube-dl/
COMMENT=	Download videos from youtube.com

DIST_SUBDIR=	${PKGNAME_NOREV}

USE_LANGUAGES=			# none
PYTHON_VERSIONS_ACCEPTED=	24
WRKSRC=				${WRKDIR}

INSTALLATION_DIRS=	bin

SUBST_CLASSES+=		path
SUBST_MESSAGE.path=	Fixing paths.
SUBST_STAGE.path=	pre-build
SUBST_FILES.path=	youtube-dl
SUBST_SED.path=         -e 's,/usr/bin/env python,${PYTHONBIN},g'

do-build:

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/youtube-dl ${PREFIX}/bin

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
