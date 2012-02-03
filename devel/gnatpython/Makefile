# $NetBSD: Makefile,v 1.4 2012/02/03 13:15:39 obache Exp $
#

DISTNAME=	gnatpython-${SNAPSHOT}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://downloads.dragonlace.net/src/ \
		http://dragonlace.mirrors.ada.cx/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER= 	draco@marino.st
HOMEPAGE=	http://forge.open-do.org/projects/gnatpython
COMMENT=	Python package used in Ada testsuites
LICENSE= 	gnu-gpl-v3
SNAPSHOT=	20110912

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_VERSIONS_ACCEPTED= 27 26 # uses "with ... as"

EGG_NAME=	gnatpython-1.2

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
