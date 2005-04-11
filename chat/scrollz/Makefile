# $NetBSD: Makefile,v 1.9 2005/04/11 21:45:05 tv Exp $
#

DISTNAME=	ScrollZ-1.9
PKGNAME=	scrollz-1.9
CATEGORIES=	chat
MASTER_SITES=	ftp://ftp.scrollz.com/pub/ScrollZ/source/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.scrollz.com/
COMMENT=	Advanced IRC client based on ircII client

BUILD_DEFS+=	USE_INET6

GNU_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"

.if defined(USE_INET6) && !empty(USE_INET6:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.include "../../mk/bsd.pkg.mk"
