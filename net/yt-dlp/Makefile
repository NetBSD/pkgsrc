# $NetBSD: Makefile,v 1.4 2021/12/01 14:32:32 ryoon Exp $

DISTNAME=	yt-dlp-2021.12.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PYPI:=y/yt-dlp/}
# \TODO: create symlink, as mpv makes use of youtube-dl?
# CONFLICTS=	youtube-dl-[0-9]*

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/yt-dlp/yt-dlp
COMMENT=	Youtube-dl fork with new features and patches
LICENSE=	unlicense

USE_LANGUAGES=	# none

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

post-install:
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/yt-dlp.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

# Only for >= 3.6
PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
