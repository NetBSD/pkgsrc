# $NetBSD: Makefile,v 1.17 2022/08/07 06:51:25 wiz Exp $

DISTNAME=	yt-dlp-2022.7.18
CATEGORIES=	net
PKGREVISION=	1
MASTER_SITES=	${MASTER_SITE_PYPI:=y/yt-dlp/}
# \TODO: create symlink, as mpv makes use of youtube-dl?
# CONFLICTS=	youtube-dl-[0-9]*

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/yt-dlp/yt-dlp
COMMENT=	Youtube-dl fork with new features and patches
LICENSE=	unlicense

USE_LANGUAGES=	# none

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	setup.py
SUBST_SED.paths=	-e "s,share/man/man1,${PKGMANDIR}/man1,"

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_PKG_RESOURCES=	yes

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
