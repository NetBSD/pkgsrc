# $NetBSD: Makefile,v 1.22 2010/08/15 02:44:59 obache Exp $

VERSION_DATE=	2010.08.04
DISTNAME=	youtube-dl
PKGNAME=	youtube-dl-${VERSION_DATE:S/.//g}
CATEGORIES=	net
MASTER_SITES=	http://bitbucket.org/rg3/youtube-dl/raw/${VERSION_DATE}/
EXTRACT_SUFX=	# none
DIST_SUBDIR=	${PKGNAME_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://bitbucket.org/rg3/youtube-dl/
COMMENT=	Download videos from youtube.com
LICENSE=	public-domain

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=			# none
NO_BUILD=			yes
WRKSRC=				${WRKDIR}

INSTALLATION_DIRS=	bin

REPLACE_PYTHON+=	${DISTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} \
	  ${DESTDIR}${PREFIX}/bin/youtube-dl

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
