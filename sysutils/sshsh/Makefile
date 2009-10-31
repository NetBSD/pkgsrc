# $NetBSD: Makefile,v 1.5 2009/10/31 19:53:17 tnn Exp $
#

DISTNAME=		sshsh-1.0
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.gw.com/pub/people/kim/

MAINTAINER=		kim@tac.nyc.ny.us
COMMENT=		Run a new shell with an SSH identity

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=		yes
BUILD_TARGET=		all PREFIX=${PREFIX}
INSTALL_TARGET=		install PREFIX=${PREFIX}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
