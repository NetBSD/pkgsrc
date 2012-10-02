# $NetBSD: Makefile,v 1.9 2012/10/02 23:48:06 asau Exp $

DISTNAME=	python-musicbrainz2-0.4.1
PKGNAME=	${DISTNAME:S/python/${PYPKGPREFIX}/}
PKGREVISION=	2
CATEGORIES=	audio python
MASTER_SITES=	http://users.musicbrainz.org/~matt/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://musicbrainz.org/doc/PythonMusicBrainz2
COMMENT=	Python interface to the MusicBrainz XML web service
LICENSE=	modified-bsd

.include "../../lang/python/pyversion.mk"

DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

EGG_NAME=	${DISTNAME:S/-/_/}

.include "../../audio/libdiscid/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
