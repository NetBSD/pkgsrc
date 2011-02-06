# $NetBSD: Makefile,v 1.17 2011/02/06 14:22:29 mlelstv Exp $
#

DISTNAME=	libdnet-1.12
PKGREVISION=	1
CATEGORIES=	devel net
MASTER_SITES=	http://libdnet.googlecode.com/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/libdnet/
COMMENT=	C interface to several low-level networking routines

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	autoconf gmake
USE_LIBTOOL=	yes

BUILD_DEFS+=	IPV6_READY

pre-configure:
	cd ${WRKSRC} && autoconf -f

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
