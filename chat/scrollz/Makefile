# $NetBSD: Makefile,v 1.13 2009/06/30 00:07:11 joerg Exp $
#

DISTNAME=	ScrollZ-1.9.5
PKGNAME=	scrollz-1.9.5
CATEGORIES=	chat
MASTER_SITES=	ftp://ftp.scrollz.com/pub/ScrollZ/source/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.scrollz.com/
COMMENT=	Advanced IRC client based on ircII client

MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=	yes

PKG_OPTIONS_VAR=	PKG_OPTIONS.scrollz
PKG_SUPPORTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.include "../../mk/bsd.pkg.mk"
