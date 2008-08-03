# $NetBSD: Makefile,v 1.7 2008/08/03 09:19:02 tnn Exp $
#

DISTNAME=	youtube-dl-2008.07.26
PKGNAME=	${DISTNAME:S/.//g}
CATEGORIES=	net
MASTER_SITES=	http://www.arrakis.es/~rggi3/youtube-dl/
EXTRACT_SUFX=	# none

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.arrakis.es/~rggi3/youtube-dl/
COMMENT=	Download videos from youtube.com

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=			# none
PYTHON_VERSIONS_ACCEPTED=	25 24
NO_BUILD=			yes
WRKSRC=				${WRKDIR}

INSTALLATION_DIRS=	bin

REPLACE_PYTHON+=	${DISTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} \
	  ${DESTDIR}${PREFIX}/bin/youtube-dl

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
