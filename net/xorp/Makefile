# $NetBSD: Makefile,v 1.3 2003/07/17 22:52:05 grant Exp $
#

DISTNAME=	xorp-0.3
CATEGORIES=	net
MASTER_SITES=	http://www.xorp.org/release-0.3/

MAINTAINER=	packages@NetBSD.org
HOMEPAGE=	http://www.xorp.org/
COMMENT=	Open router software platform

# cli/libtecla/configure.in bombs if ncurses is installed
CONFLICTS+=	ncurses-[0-9]*

HAS_CONFIGURE=	YES
GNU_CONFIGURE=	YES
USE_GMAKE=	YES
CONFIGURE_ARGS+=--sysconfdir=${PKG_SYSCONFDIR}

.include "../../mk/bsd.pkg.mk"
