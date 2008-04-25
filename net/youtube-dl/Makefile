# $NetBSD: Makefile,v 1.5 2008/04/25 20:39:11 joerg Exp $
#

DISTNAME=	youtube-dl
PKGNAME=	youtube-dl-20080308
CATEGORIES=	net
MASTER_SITES=	http://www.arrakis.es/~rggi3/youtube-dl/
EXTRACT_SUFX=	# none

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.arrakis.es/~rggi3/youtube-dl/
COMMENT=	Download videos from youtube.com

DIST_SUBDIR=	${PKGNAME_NOREV}
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=			# none
PYTHON_VERSIONS_ACCEPTED=	25 24
WRKSRC=				${WRKDIR}

INSTALLATION_DIRS=	bin

SUBST_CLASSES+=		path
SUBST_MESSAGE.path=	Fixing paths.
SUBST_STAGE.path=	pre-build
SUBST_FILES.path=	youtube-dl
SUBST_SED.path=         -e 's,/usr/bin/env python,${PYTHONBIN},g'

do-build:

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/youtube-dl ${DESTDIR}${PREFIX}/bin

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
