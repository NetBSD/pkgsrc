# $NetBSD: Makefile,v 1.1 2025/11/18 11:08:20 ryoon Exp $

DISTNAME=	yt_dlp_ejs-0.3.1
PKGNAME=	${DISTNAME:S/_/-/g}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=y/yt_dlp_ejs/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://pypi.org/project/yt_dlp_ejs/
COMMENT=	External JavaScript for net/yt-dlp supporting many runtimes
LICENSE=	unlicense

# Do not rebuild support scripts in JavaScript.
# Rebuilding from source requires many porting efforts for Node JS packages.
YTDLPZIP=		yt-dlp_linux.zip
SITES.${YTDLPZIP}=	https://github.com/yt-dlp/yt-dlp/releases/download/2025.11.12/
DISTFILES=	${DEFAULT_DISTFILES} ${YTDLPZIP}

DEPENDS+=	yt-dlp-[0-9]*:../../net/yt-dlp

USE_LANGUAGES=	# none

NO_BUILD=	yes

INSTALLATION_DIRS+=	${PYSITELIB}/yt_dlp_ejs/yt/solver

PLIST_SUBST=	PYSITELIB=${PYSITELIB}

post-extract:
	${CP} ${WRKDIR}/_internal/yt_dlp_ejs/yt/solver/*.js \
		${WRKSRC}/yt_dlp_ejs/yt/solver

do-install:
	${CP} -r ${WRKSRC}/yt_dlp_ejs \
		${DESTDIR}${PREFIX}/${PYSITELIB}

.include "../../lang/python/pyversion.mk"
.include "../../lang/nodejs/nodeversion.mk"
.include "../../mk/bsd.pkg.mk"
