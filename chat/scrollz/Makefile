# $NetBSD: Makefile,v 1.5 2004/03/29 08:05:07 xtraeme Exp $
#

DISTNAME=	ScrollZ-1.9
PKGNAME=	scrollz-1.9
CATEGORIES=	chat
MASTER_SITES=   http://scrollz.broken.com/source/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.scrollz.com/
COMMENT=        Advanced IRC client based on ircII client

BUILD_DEFS+=	USE_INET6

GNU_CONFIGURE=	yes
USE_BUILDLINK3=	yes

.include "../../mk/bsd.prefs.mk"

.if defined(USE_INET6) && !empty(USE_INET6:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.include "../../mk/bsd.pkg.mk"
