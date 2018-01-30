# $NetBSD: Makefile,v 1.21 2018/01/30 14:10:11 adam Exp $

DISTNAME=	beets-1.4.6
CATEGORIES=	audio python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/beets/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://beets.io/
COMMENT=	Music geek's media organizer
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-Unidecode-[0-9]*:../../textproc/py-Unidecode
DEPENDS+=	${PYPKGPREFIX}-jellyfish-[0-9]*:../../textproc/py-jellyfish
DEPENDS+=	${PYPKGPREFIX}-last-[0-9]*:../../audio/py-last
DEPENDS+=	${PYPKGPREFIX}-munkres-[0-9]*:../../math/py-munkres
DEPENDS+=	${PYPKGPREFIX}-musicbrainz-ngs>=0.4:../../audio/py-musicbrainz-ngs
DEPENDS+=	${PYPKGPREFIX}-mutagen>=1.33:../../audio/py-mutagen
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-six>=1.9:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
DEPENDS+=	${PYPKGPREFIX}-enum34-[0-9]*:../../devel/py-enum34
.endif

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} beet beet${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
