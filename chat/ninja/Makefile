# $NetBSD: Makefile,v 1.8 2004/06/08 12:23:59 cjep Exp $
#

DISTNAME=	ninja-1.5.8.1
CATEGORIES=	chat
MASTER_SITES=	ftp://ninja.qoop.org/ninja/sources/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://ninja.qoop.org/
COMMENT=	Another IRC client based on ircII

USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES
USE_GNU_TOOLS+=	make

BUILD_DEFS+=		USE_INET6

.if defined(USE_INET6) && ${USE_INET6} == "YES"
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.include "../../mk/bsd.pkg.mk"
