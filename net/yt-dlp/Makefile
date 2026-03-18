# $NetBSD: Makefile,v 1.90 2026/03/18 09:16:29 wiz Exp $

DISTNAME=	yt_dlp-2026.3.17
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PYPI:=y/yt-dlp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/yt-dlp/yt-dlp
COMMENT=	Youtube-dl fork with new features and patches
LICENSE=	unlicense

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.27.0:../../devel/py-hatchling

USE_LANGUAGES=	# none

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	pyproject.toml
SUBST_SED.paths=	-e "s,share/man/man1,${PKGMANDIR}/man1,"

post-install:
	${RM} -fr ${DESTDIR}${PREFIX}/${PYSITELIB}/devscripts

.if make(test)
ALLOW_NETWORK_ACCESS=	yes
.endif

# as of 2026.2.21
# 2483 failed, 3819 passed, 1121 skipped, 3 warnings, 39 subtests passed

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
