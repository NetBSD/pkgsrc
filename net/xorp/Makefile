# $NetBSD: Makefile,v 1.7 2004/02/14 15:29:15 jlam Exp $
#

DISTNAME=	xorp-0.3
CATEGORIES=	net
MASTER_SITES=	http://www.xorp.org/release-0.3/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.xorp.org/
COMMENT=	Open router software platform

# cli/libtecla/configure.in bombs if ncurses is installed
CONFLICTS+=	ncurses-[0-9]*

GNU_CONFIGURE=		YES
USE_GNU_TOOLS+=		make
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

.include "../../mk/bsd.pkg.mk"
