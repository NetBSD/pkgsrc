# $NetBSD: Makefile,v 1.13 2014/05/09 07:36:54 wiz Exp $

DISTNAME=	python-musicbrainz2-0.4.1
PKGNAME=	${DISTNAME:S/python/${PYPKGPREFIX}/}
PKGREVISION=	3
CATEGORIES=	audio python
MASTER_SITES=	http://users.musicbrainz.org/~matt/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://musicbrainz.org/doc/PythonMusicBrainz2
COMMENT=	Python interface to the MusicBrainz XML web service
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

PYTHON_SELF_CONFLICT=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	33 34

EGG_NAME=	${DISTNAME:S/-/_/}

.include "../../audio/libdiscid/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
