# $NetBSD: Makefile,v 1.8 2011/03/18 20:36:46 zafer Exp $
#

DISTNAME=		cpogm-1.0
CATEGORIES=		sysutils
MASTER_SITES=	# ftp://ftp.gw.com/pub/people/kim/

MAINTAINER=		kim@tac.nyc.ny.us
COMMENT=		Copy owner, group and mode of a file

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		perl:run

NO_CONFIGURE=		yes
BUILD_TARGET=		all PREFIX=${PREFIX}
INSTALL_MAKE_FLAGS+=	PREFIX=${PREFIX}
INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man8

.include "../../mk/bsd.pkg.mk"
