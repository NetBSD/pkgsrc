# $NetBSD: Makefile,v 1.6 2004/04/11 05:57:30 snj Exp $
#

DISTNAME=	ninja-1.5.8.1
CATEGORIES=	chat
MASTER_SITES=	ftp://ninja.qoop.org/ninja/sources/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://ninja.qoop.org/
COMMENT=	Another IRC client based on ircII

USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES
USE_GNU_TOOLS+=	make

.if defined(USE_INET6) && ${USE_INET6} == "YES"
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.include "../../mk/bsd.pkg.mk"
