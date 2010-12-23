# $NetBSD: Makefile,v 1.23 2010/12/23 18:21:16 tron Exp $

VERSION_DATE=	2010.12.09
DISTNAME=	youtube-dl
PKGNAME=	youtube-dl-${VERSION_DATE:S/.//g}
CATEGORIES=	net
MASTER_SITES=	http://github.com/rg3/youtube-dl/${VERSION_DATE}/
EXTRACT_SUFX=	# none
DIST_SUBDIR=	${PKGNAME_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rg3.github.com/youtube-dl/
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
