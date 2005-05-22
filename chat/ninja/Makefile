# $NetBSD: Makefile,v 1.10 2005/05/22 20:07:43 jlam Exp $
#

DISTNAME=	ninja-1.5.8.1
CATEGORIES=	chat
MASTER_SITES=	ftp://ninja.qoop.org/ninja/sources/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://ninja.qoop.org/
COMMENT=	Another IRC client based on ircII

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake

BUILD_DEFS+=		USE_INET6

.if defined(USE_INET6) && ${USE_INET6} == "YES"
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.include "../../mk/bsd.pkg.mk"
