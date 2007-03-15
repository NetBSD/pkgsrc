# $NetBSD: Makefile,v 1.6 2007/03/15 18:37:57 joerg Exp $
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
INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man8

.include "../../mk/bsd.pkg.mk"
