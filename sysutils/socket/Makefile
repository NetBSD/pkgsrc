# $NetBSD: Makefile,v 1.11 2005/03/24 21:13:01 wiz Exp $

DISTNAME=	socket-1.1
CATEGORIES=	sysutils net
MASTER_SITES=	http://www.freebsd.org/~wosch/src/

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Create tcp socket and connect to stdin/out

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
