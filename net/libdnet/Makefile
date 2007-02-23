# $NetBSD: Makefile,v 1.13 2007/02/23 20:33:05 drochner Exp $
#

DISTNAME=	libdnet-1.11
CATEGORIES=	devel net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libdnet/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libdnet.sourceforge.net/
COMMENT=	C interface to several low-level networking routines

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_LIBTOOL=	yes

BUILD_DEFS+=	USE_INET6

PKG_OPTIONS_VAR=	PKG_OPTIONS.libdnet
PKG_SUPPORTED_OPTIONS=	libdnetcheck
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlibdnetcheck)
.include "../../devel/check/buildlink3.mk"
TEST_TARGET=	check
.else
CONFIGURE_ARGS+=	--without-check
.endif

.include "../../mk/bsd.pkg.mk"
