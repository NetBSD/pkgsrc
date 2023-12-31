# $NetBSD: Makefile,v 1.35 2023/12/31 07:58:02 adam Exp $

DISTNAME=	yt-dlp-2023.12.30
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PYPI:=y/yt-dlp/}
# TODO: create symlink, as mpv makes use of youtube-dl?
# CONFLICTS=	youtube-dl-[0-9]*

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/yt-dlp/yt-dlp
COMMENT=	Youtube-dl fork with new features and patches
LICENSE=	unlicense

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

USE_LANGUAGES=	# none

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	setup.py
SUBST_SED.paths=	-e "s,share/man/man1,${PKGMANDIR}/man1,"

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	${RM} -fr ${DESTDIR}${PREFIX}/${PYSITELIB}/devscripts

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
