# $NetBSD: Makefile,v 1.2 2011/02/25 09:47:20 wiz Exp $
#

DISTNAME=	gnatpython-${SNAPSHOT}
CATEGORIES=	devel
MASTER_SITES=	http://downloads.dragonlace.net/src/ \
		http://dragonlace.mirrors.ada.cx/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER= 	draco@marino.st
HOMEPAGE=	http://forge.open-do.org/projects/gnatpython
COMMENT=	Python package used in Ada testsuites
LICENSE= 	gnu-gpl-v3
SNAPSHOT=	20101207

PKG_DESTDIR_SUPPORT=	user-destdir
PYDISTUTILSPKG=		yes
PYTHON_VERSIONS_ACCEPTED= 27 26 # uses "with ... as"

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
