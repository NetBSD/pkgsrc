# $NetBSD: Makefile,v 1.4 2012/10/02 23:48:06 asau Exp $
#

DISTNAME=	python-mpd-0.2.0
PKGNAME=	${PYPKGPREFIX}-mpd-0.2.0
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://pypi.python.org/packages/source/p/python-mpd/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.musicpd.org/~jat/python-mpd/
COMMENT=	Python mpd client library
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none

EGG_NAME=	${DISTNAME:S/-/_/}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
