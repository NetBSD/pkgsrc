# $NetBSD: Makefile,v 1.13 2009/06/09 23:02:18 snj Exp $

DISTNAME=	youtube-dl
PKGNAME=	youtube-dl-20090530 # master site needs to be updated in tandem
CATEGORIES=	net
MASTER_SITES=	http://bitbucket.org/rg3/youtube-dl/raw/2009.05.30/
EXTRACT_SUFX=	# none
DIST_SUBDIR=	${PKGNAME_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://bitbucket.org/rg3/youtube-dl/
COMMENT=	Download videos from youtube.com

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=			# none
PYTHON_VERSIONS_ACCEPTED=	26 25 24
NO_BUILD=			yes
WRKSRC=				${WRKDIR}

INSTALLATION_DIRS=	bin

REPLACE_PYTHON+=	${DISTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} \
	  ${DESTDIR}${PREFIX}/bin/youtube-dl

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
