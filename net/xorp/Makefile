# $NetBSD: Makefile,v 1.1.1.1 2003/07/15 12:15:01 itojun Exp $
#

DISTNAME=	xorp-0.3
CATEGORIES=	FILLTHISINPLEASE
MASTER_SITES=	http://www.xorp.org/release-0.3/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.xorp.org/
COMMENT=	Open router software platform

# cli/libtecla/configure.in bombs if ncurses is installed
CONFLICTS+=	ncurses-[0-9]*

HAS_CONFIGURE=	YES
GNU_CONFIGURE=	YES
USE_GMAKE=	YES
CONFIGURE_ARGS+=--sysconfdir=${PKG_SYSCONFDIR}

.include "../../mk/bsd.pkg.mk"
