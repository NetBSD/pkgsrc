# $NetBSD: Makefile,v 1.2 2002/12/13 12:54:43 grant Exp $
#

DISTNAME=	ScrollZ-1.8m
PKGNAME=	scrollz-1.8m
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
