# $NetBSD: Makefile,v 1.9 2013/03/14 13:03:47 kim Exp $
#

DISTNAME=		osname-2.0
CATEGORIES=		sysutils
MASTER_SITES=		http://oss.gw.com/people/kim/

MAINTAINER=		kim@tac.nyc.ny.us
COMMENT=		Print canonical name of operating system

NO_CONFIGURE=		yes
BUILD_MAKE_FLAGS+=	PREFIX=${PREFIX}
INSTALL_MAKE_FLAGS+=	PREFIX=${PREFIX}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
