# $NetBSD: Makefile,v 1.10 2022/01/31 23:27:20 ryoon Exp $

DISTNAME=	yt-dlp-2022.1.21
PKGREVISION=	1
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

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	setup.py
SUBST_VARS.paths=	PKGMANDIR

# Only for >= 3.6
PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_PKG_RESOURCES=	yes

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
