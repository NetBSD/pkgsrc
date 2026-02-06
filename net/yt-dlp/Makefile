# $NetBSD: Makefile,v 1.86 2026/02/06 15:26:34 wiz Exp $

DISTNAME=	yt_dlp-2026.2.4
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

# as of 2026.2.4
# 2424 failed, 3849 passed, 1118 skipped, 3 warnings, 21 subtests passed

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
