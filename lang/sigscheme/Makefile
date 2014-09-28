# $NetBSD: Makefile,v 1.8 2014/09/28 03:18:07 obache Exp $
#

DISTNAME=	sigscheme-0.8.5
CATEGORIES=	lang
MASTER_SITES=	http://sigscheme.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/sigscheme/
COMMENT=	R5RS Scheme interpreter for embedded use
#LICENSE=	# See ${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

PKGCONFIG_OVERRIDE+=	libgcroots/gcroots.pc.in
PKGCONFIG_OVERRIDE+=	sigscheme.pc.in

CONFIGURE_ARGS+=	--enable-conf=full
CONFIGURE_ARGS+=	--with-libgcroots=installed

TEST_TARGET=	check

CFLAGS+=		--std=c99

.include "../../devel/libgcroots/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
