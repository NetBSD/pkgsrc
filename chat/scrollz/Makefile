# $NetBSD: Makefile,v 1.1.1.1 2002/12/06 18:25:22 grant Exp $
#

DISTNAME=	ScrollZ-1.8l
PKGNAME=	scrollz-1.8l
CATEGORIES=	chat
MASTER_SITES=   http://scrollz.broken.com/source/
EXTRACT_SUFX=   .tar.bz2

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://www.scrollz.com/
COMMENT=        Advanced IRC client based on ircII client

BUILD_DEFS+=	USE_INET6

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES

.include "../../mk/bsd.prefs.mk"

.if defined(USE_INET6) && ${USE_INET6} == YES
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.include "../../mk/bsd.pkg.mk"
