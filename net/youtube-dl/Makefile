# $NetBSD: Makefile,v 1.82 2016/02/25 19:07:59 leot Exp $

VERSION_DATE=	2016.02.22
DISTNAME=	youtube-dl-${VERSION_DATE}
PKGNAME=	youtube-dl-${VERSION_DATE:S/.//g}
CATEGORIES=	net
MASTER_SITES=	http://youtube-dl.org/downloads/${VERSION_DATE}/

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	http://rg3.github.io/youtube-dl/
COMMENT=	Download videos from youtube.com
LICENSE=	public-domain

# Unfortunately at the moment upstream youtube-dl does not provide a changelog.
# When updating net/youtube-dl you can find a complete list of changes here:
#  https://github.com/rg3/youtube-dl/compare/${OLD_VERSION_DATE}...${NEW_VERSION_DATE}
# ...where OLD_VERSION_DATE is the previous VERSION_DATE and NEW_VERSION_DATE is
# the version you are going to commit.

USE_LANGUAGES=	# none
EGG_NAME=	youtube_dl-${VERSION_DATE:S/.0/./g}
WRKSRC=		${WRKDIR}/youtube-dl

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
