# $NetBSD: Makefile,v 1.3 2003/08/12 13:38:54 grant Exp $
#

DISTNAME=	ninja-1.5.8.1
CATEGORIES=	chat
MASTER_SITES=	ftp://ninja.qoop.org/ninja/sources/

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://ninja.qoop.org/
COMMENT=	Another IRC client based on ircII

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
USE_GMAKE=	YES

.if defined(USE_INET6) && ${USE_INET6} == "YES"
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.include "../../mk/bsd.pkg.mk"
