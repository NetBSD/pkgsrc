# $NetBSD: Makefile,v 1.5 2009/08/09 21:51:13 wiz Exp $

DISTNAME=	python-musicbrainz2-0.4.1
PKGNAME=	${DISTNAME:S/python/${PYPKGPREFIX}/}
CATEGORIES=	audio python
MASTER_SITES=	http://users.musicbrainz.org/~matt/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://musicbrainz.org/doc/PythonMusicBrainz2
COMMENT=	Python interface to the MusicBrainz XML web service
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes

DEPENDS+=	${PYPKGPREFIX}-ctypes>=1.0.0:../../devel/py-ctypes
DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

.include "../../audio/libdiscid/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
