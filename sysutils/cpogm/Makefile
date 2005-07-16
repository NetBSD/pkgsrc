# $NetBSD: Makefile,v 1.5 2005/07/16 01:19:20 jlam Exp $
#

DISTNAME=		cpogm-1.0
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.gw.com/pub/people/kim/

MAINTAINER=		kim@tac.nyc.ny.us
COMMENT=		Copy owner, group and mode of a file

USE_TOOLS+=		perl:run

NO_CONFIGURE=		yes
BUILD_TARGET=		all PREFIX=${PREFIX}
INSTALL_TARGET=		install PREFIX=${PREFIX}

.include "../../mk/bsd.pkg.mk"
