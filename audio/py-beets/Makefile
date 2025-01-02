# $NetBSD: Makefile,v 1.35 2025/01/02 10:21:02 adam Exp $

DISTNAME=	beets-2.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	audio python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/beets/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://beets.io/
COMMENT=	Music geek's media organizer
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=1.0.0:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-Unidecode>=1.3.6:../../textproc/py-Unidecode
DEPENDS+=	${PYPKGPREFIX}-confuse>=1.5.0:../../devel/py-confuse
DEPENDS+=	${PYPKGPREFIX}-jellyfish-[0-9]*:../../textproc/py-jellyfish
DEPENDS+=	${PYPKGPREFIX}-mediafile>=0.12.0:../../audio/py-mediafile
DEPENDS+=	${PYPKGPREFIX}-munkres>=1.0.0:../../math/py-munkres
DEPENDS+=	${PYPKGPREFIX}-musicbrainz-ngs>=0.4:../../audio/py-musicbrainz-ngs
DEPENDS+=	${PYPKGPREFIX}-platformdirs>=3.5.0:../../misc/py-platformdirs
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
# update
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
# lastgenre
DEPENDS+=	${PYPKGPREFIX}-last-[0-9]*:../../audio/py-last
# scrub
DEPENDS+=	${PYPKGPREFIX}-mutagen>=1.33:../../audio/py-mutagen
TEST_DEPENDS+=	${PYPKGPREFIX}-discogs-client-[0-9]*:../../audio/py-discogs-client
TEST_DEPENDS+=	${PYPKGPREFIX}-mpd2-[0-9]*:../../audio/py-mpd2
TEST_DEPENDS+=	${PYPKGPREFIX}-requests-oauthlib-[0-9]*:../../security/py-requests-oauthlib
TEST_DEPENDS+=	${PYPKGPREFIX}-responses>=0.3.0:../../net/py-responses
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

USE_LANGUAGES=	# none

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-typing-extensions-[0-9]*:../../devel/py-typing-extensions
.endif

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} beet beet-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
