# $NetBSD: Makefile,v 1.6 1999/09/17 18:23:54 tron Exp $
# FreeBSD Id: Makefile,v 1.7 1997/08/16 10:14:56 wosch Exp
#

DISTNAME=	socket-1.1
CATEGORIES=	sysutils net
MASTER_SITES=	http://www.freebsd.org/~wosch/src/

MAINTAINER=	packages@netbsd.org

MAKE_ENV+=	INSTALLBASE=${PREFIX}

BUILD_DEFS+=    USE_INET6

# to get USE_INET6
.include "../../mk/bsd.prefs.mk"

# IPv6 support
.if defined(USE_INET6) && ${USE_INET6} == YES
MAKE_ENV+=	SWITCHES="-DUSE_INET6 -DHAVE_SYS_PARAM_H -Wall"
.else
MAKE_ENV+=	SWITCHES="-DHAVE_SYS_PARAM_H -Wall"
.endif

.include "../../mk/bsd.pkg.mk"
