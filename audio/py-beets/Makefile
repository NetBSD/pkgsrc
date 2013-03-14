# $NetBSD: Makefile,v 1.2 2013/03/14 21:36:19 drochner Exp $
#

DISTNAME=	v1.0.0
PKGNAME=	${PYPKGPREFIX}-beets-${DISTNAME:S/v//}
CATEGORIES=	audio
MASTER_SITES=	https://github.com/sampsyo/beets/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	https://github.com/sampsyo/beets
HOMEPAGE=	http://beets.radbox.org/
COMMENT=	Music geek's media organizer
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-last-[0-9]*:../../audio/py-last
DEPENDS+=	${PYPKGPREFIX}-munkres-[0-9]*:../../math/py-munkres
DEPENDS+=	${PYPKGPREFIX}-musicbrainz-ngs-[0-9]*:../../audio/py-musicbrainz-ngs
DEPENDS+=	${PYPKGPREFIX}-mutagen-[0-9]*:../../audio/py-mutagen
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-Unidecode-[0-9]*:../../textproc/py-Unidecode
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3

DIST_SUBDIR=	py-beets
WRKSRC=		${WRKDIR}/beets-${DISTNAME:S/v//}
USE_LANGUAGES=	# none
PLIST_SUBST+=			PYVERSSUFFIX=${PYVERSSUFFIX}
EGG_NAME=	beets-${DISTNAME:S/v//}

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/beet ${DESTDIR}${PREFIX}/bin/beet${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
