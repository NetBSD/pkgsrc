# $NetBSD: Makefile,v 1.4 2009/05/28 20:42:27 zafer Exp $

DISTNAME=	python-musicbrainz2-0.4.0
PKGNAME=	${DISTNAME:S/python/${PYPKGPREFIX}/}
CATEGORIES=	audio python
MASTER_SITES=	http://users.musicbrainz.org/~matt/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://musicbrainz.org/doc/PythonMusicBrainz2
COMMENT=	Python interface to the MusicBrainz XML web service

PYDISTUTILSPKG=	yes

DEPENDS+=	${PYPKGPREFIX}-ctypes>=1.0.0:../../devel/py-ctypes
DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

.include "../../audio/libdiscid/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
