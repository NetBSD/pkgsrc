# $NetBSD: Makefile,v 1.3 2011/10/06 22:15:21 marino Exp $
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
SNAPSHOT=	20110912

PKG_DESTDIR_SUPPORT=	user-destdir
PYDISTUTILSPKG=		yes
PYTHON_VERSIONS_ACCEPTED= 27 26 # uses "with ... as"

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
