# $NetBSD: Makefile,v 1.26 2020/01/26 17:30:44 rillig Exp $

DISTNAME=	beets-1.4.9
PKGREVISION=	1
CATEGORIES=	audio python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/beets/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://beets.io/
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

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-jellyfish

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} beet beet-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
