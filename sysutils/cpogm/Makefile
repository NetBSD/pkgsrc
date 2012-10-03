# $NetBSD: Makefile,v 1.9 2012/10/03 21:57:36 wiz Exp $
#

DISTNAME=		cpogm-1.0
PKGREVISION=		1
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
