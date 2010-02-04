# $NetBSD: Makefile,v 1.16 2010/02/04 20:58:45 heinz Exp $

DISTNAME=	socket-1.1
CATEGORIES=	sysutils net
MASTER_SITES=	http://www.freebsd.org/~wosch/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Create tcp socket and connect to stdin/out
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_ENV+=	INSTALLBASE=${PREFIX:Q}

PKG_OPTIONS_VAR=	PKG_OPTIONS.socket
PKG_SUPPORTED_OPTIONS=	inet6

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.options.mk"

###
### IPv6 support
###
.if !empty(PKG_OPTIONS:Minet6)
MAKE_ENV+=	SWITCHES="-DUSE_INET6 -DHAVE_SYS_PARAM_H -Wall"
.else
MAKE_ENV+=	SWITCHES="-DHAVE_SYS_PARAM_H -Wall"
.endif

.include "../../mk/bsd.pkg.mk"
