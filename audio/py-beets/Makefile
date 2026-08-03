# $NetBSD: Makefile,v 1.59 2026/08/03 17:48:45 wiz Exp $

DISTNAME=	beets-2.13.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	audio python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/beets/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://beets.io/
COMMENT=	Music geek's media organizer
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-Unidecode>=1.3.6:../../textproc/py-Unidecode
DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4>=0:../../www/py-beautifulsoup4
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
DEPENDS+=	${PYPKGPREFIX}-titlecase>=0:../../devel/py-titlecase
DEPENDS+=	${PYPKGPREFIX}-typing-extensions-[0-9]*:../../devel/py-typing-extensions
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
# lastgenre
DEPENDS+=	${PYPKGPREFIX}-last-[0-9]*:../../audio/py-last
# scrub
DEPENDS+=	${PYPKGPREFIX}-mutagen>=1.33:../../audio/py-mutagen
# ffprobe
DEPENDS+=	ffmpeg8-[0-9]*:../../multimedia/ffmpeg8
TEST_DEPENDS+=	${PYPKGPREFIX}-discogs-client-[0-9]*:../../audio/py-discogs-client
TEST_DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-mpd2-[0-9]*:../../audio/py-mpd2
TEST_DEPENDS+=	${PYPKGPREFIX}-requests-oauthlib-[0-9]*:../../security/py-requests-oauthlib
TEST_DEPENDS+=	${PYPKGPREFIX}-responses>=0.3.0:../../net/py-responses
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-factoryboy-[0-9]*:../../devel/py-test-factoryboy
TEST_DEPENDS+=	${PYPKGPREFIX}-xdg-[0-9]*:../../devel/py-xdg

USE_LANGUAGES=	# none
USE_TOOLS+=	git

INSTALLATION_DIRS+=	${PKGMANDIR}/man1 ${PKGMANDIR}/man5

PYTHON_VERSIONS_INCOMPATIBLE=	310 311
PY_RENAME_BINARIES=		beet

SUBST_CLASSES+=		ffprobe
SUBST_FILES.ffprobe+=	beets/util/extension.py
SUBST_FILES.ffprobe+=	test/test_importer.py
SUBST_SED.ffprobe+=	-e 's,ffprobe,ffprobe8,'
SUBST_STAGE.ffprobe=	pre-configure
SUBST_MESSAGE.ffprobe=	Fixing ffprobe file name.

.if make(test)
ALLOW_NETWORK_ACCESS=	yes
.endif
# as of 2.13.1
# 2460 passed, 178 skipped, 200 warnings, 91 errors

post-install:
	${INSTALL_DATA} ${WRKSRC}/man/beet.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/beet-${PYVERSSUFFIX}.1
	${INSTALL_DATA} ${WRKSRC}/man/beetsconfig.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/beetsconfig-${PYVERSSUFFIX}.5

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
