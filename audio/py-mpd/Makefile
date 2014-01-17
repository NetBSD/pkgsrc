# $NetBSD: Makefile,v 1.6 2014/01/17 14:47:25 wiz Exp $

DISTNAME=	python-mpd-0.3.0
PKGNAME=	${PYPKGPREFIX}-mpd-0.3.0
CATEGORIES=	audio
MASTER_SITES=	http://pypi.python.org/packages/source/p/python-mpd/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.musicpd.org/~jat/python-mpd/
COMMENT=	Python mpd client library
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	# none

EGG_NAME=	${DISTNAME:S/-/_/}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
