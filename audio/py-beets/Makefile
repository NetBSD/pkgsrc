# $NetBSD: Makefile,v 1.11 2014/05/09 07:36:54 wiz Exp $

DISTNAME=	v1.3.5
PKGNAME=	beets-${DISTNAME:S/v//}
CATEGORIES=	audio
MASTER_SITES=	https://github.com/sampsyo/beets/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	https://github.com/sampsyo/beets
HOMEPAGE=	http://beets.radbox.org/
COMMENT=	Music geek's media organizer
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-enum34-[0-9]*:../../devel/py-enum34
DEPENDS+=	${PYPKGPREFIX}-last-[0-9]*:../../audio/py-last
DEPENDS+=	${PYPKGPREFIX}-munkres-[0-9]*:../../math/py-munkres
DEPENDS+=	${PYPKGPREFIX}-musicbrainz-ngs>=0.4:../../audio/py-musicbrainz-ngs
DEPENDS+=	${PYPKGPREFIX}-mutagen-[0-9]*:../../audio/py-mutagen
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-Unidecode-[0-9]*:../../textproc/py-Unidecode
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-mutagen

.include "../../lang/python/pyversion.mk"
.if empty(PYPKGPREFIX:Mpy27)
DEPENDS+=	${PYPKGPREFIX}-ordereddict-[0-9]*:../../devel/py-ordereddict
.endif

DIST_SUBDIR=	py-beets
WRKSRC=		${WRKDIR}/beets-${DISTNAME:S/v//}
USE_LANGUAGES=	# none
EGG_NAME=	beets-${DISTNAME:S/v//}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
