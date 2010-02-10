# $NetBSD: Makefile,v 1.17 2010/02/10 19:17:44 joerg Exp $

DISTNAME=	youtube-dl
PKGNAME=	youtube-dl-20090808 # master site needs to be updated in tandem
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://bitbucket.org/rg3/youtube-dl/raw/2009.08.08/
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
