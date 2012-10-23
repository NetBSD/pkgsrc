# $NetBSD: Makefile,v 1.7 2012/10/23 19:51:24 asau Exp $
#

DISTNAME=		sshsh-1.0
CATEGORIES=		sysutils
MASTER_SITES=		# ftp://ftp.gw.com/pub/people/kim/

MAINTAINER=		kim@tac.nyc.ny.us
COMMENT=		Run a new shell with an SSH identity

NO_CONFIGURE=		yes
BUILD_TARGET=		all PREFIX=${PREFIX}
INSTALL_TARGET=		install PREFIX=${PREFIX}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
