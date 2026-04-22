# $NetBSD: Makefile,v 1.54 2026/04/22 08:08:37 adam Exp $

DISTNAME=	beets-2.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	audio python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/beets/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://beets.io/
COMMENT=	Music geek's media organizer
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=2.2.1:../../devel/py-poetry-core
TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-dynamic-versioning>=0:../../devel/py-poetry-dynamic-versioning
DEPENDS+=	${PYPKGPREFIX}-Unidecode>=1.3.6:../../textproc/py-Unidecode
DEPENDS+=	${PYPKGPREFIX}-confuse>=2.2.0:../../devel/py-confuse
DEPENDS+=	${PYPKGPREFIX}-jellyfish-[0-9]*:../../textproc/py-jellyfish
DEPENDS+=	${PYPKGPREFIX}-lap>=0.5.12:../../math/py-lap
DEPENDS+=	${PYPKGPREFIX}-mediafile>=0.16.2:../../audio/py-mediafile
DEPENDS+=	${PYPKGPREFIX}-musicbrainz-ngs>=0.4:../../audio/py-musicbrainz-ngs
DEPENDS+=	${PYPKGPREFIX}-numpy>=2.3.5:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-packaging>=24.0:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-platformdirs>=3.5.0:../../misc/py-platformdirs
DEPENDS+=	${PYPKGPREFIX}-requests>=2.32.5:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-requests-ratelimiter>=0.7.0:../../net/py-requests-ratelimiter
DEPENDS+=	${PYPKGPREFIX}-typing-extensions-[0-9]*:../../devel/py-typing-extensions
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
# lastgenre
DEPENDS+=	${PYPKGPREFIX}-last-[0-9]*:../../audio/py-last
# scrub
DEPENDS+=	${PYPKGPREFIX}-mutagen>=1.33:../../audio/py-mutagen
TEST_DEPENDS+=	${PYPKGPREFIX}-discogs-client-[0-9]*:../../audio/py-discogs-client
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-mpd2-[0-9]*:../../audio/py-mpd2
TEST_DEPENDS+=	${PYPKGPREFIX}-requests-oauthlib-[0-9]*:../../security/py-requests-oauthlib
TEST_DEPENDS+=	${PYPKGPREFIX}-responses>=0.3.0:../../net/py-responses
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

USE_LANGUAGES=	# none
USE_TOOLS+=	git

INSTALLATION_DIRS+=	${PKGMANDIR}/man1 ${PKGMANDIR}/man5

PYTHON_VERSIONS_INCOMPATIBLE=	310

# as of 2.8.0
# 1 failed, 849 passed, 100 skipped
.if make(test)
ALLOW_NETWORK_ACCESS=	yes
.endif

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-typing-extensions-[0-9]*:../../devel/py-typing-extensions
.endif

# https://github.com/beetbox/beets/issues/5596
post-install:
	${INSTALL_DATA} ${WRKSRC}/man/beet.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/beet-${PYVERSSUFFIX}.1
	${INSTALL_DATA} ${WRKSRC}/man/beetsconfig.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/beetsconfig-${PYVERSSUFFIX}.5
	cd ${DESTDIR}${PREFIX}/bin && ${MV} beet beet-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
