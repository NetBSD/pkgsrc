# $NetBSD: Makefile,v 1.6 2011/10/15 10:22:14 obache Exp $

DISTNAME=	python-musicbrainz2-0.4.1
PKGNAME=	${DISTNAME:S/python/${PYPKGPREFIX}/}
PKGREVISION=	1
CATEGORIES=	audio python
MASTER_SITES=	http://users.musicbrainz.org/~matt/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://musicbrainz.org/doc/PythonMusicBrainz2
COMMENT=	Python interface to the MusicBrainz XML web service
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${PYPKGPREFIX}-ctypes>=1.0.0:../../devel/py-ctypes
DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

EGG_NAME=	${DISTNAME:S/-/_/}

.include "../../audio/libdiscid/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
