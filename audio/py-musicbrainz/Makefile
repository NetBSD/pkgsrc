# $NetBSD: Makefile,v 1.19 2018/07/03 05:03:03 adam Exp $

DISTNAME=	python-musicbrainz2-0.4.1
PKGNAME=	${DISTNAME:S/python/${PYPKGPREFIX}/}
PKGREVISION=	4
CATEGORIES=	audio python
MASTER_SITES=	http://users.musicbrainz.org/~matt/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://musicbrainz.org/doc/PythonMusicBrainz2
COMMENT=	Python interface to the MusicBrainz XML web service
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

PYTHON_SELF_CONFLICT=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37

.include "../../audio/libdiscid/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
