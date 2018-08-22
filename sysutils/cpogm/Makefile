# $NetBSD: Makefile,v 1.16 2018/08/22 09:46:33 wiz Exp $
#

DISTNAME=		cpogm-1.0
PKGREVISION=		6
CATEGORIES=		sysutils
MASTER_SITES=		http://oss.gw.com/people/kim/

MAINTAINER=		kim@tac.nyc.ny.us
COMMENT=		Copy owner, group and mode of a file

USE_TOOLS+=		perl:run

NO_CONFIGURE=		yes
BUILD_TARGET=		all PREFIX=${PREFIX}
INSTALL_MAKE_FLAGS+=	PREFIX=${PREFIX}
INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man8

.include "../../mk/bsd.pkg.mk"
