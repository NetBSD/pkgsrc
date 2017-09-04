# $NetBSD: Makefile,v 1.10 2017/09/04 18:55:09 wiz Exp $
#

DISTNAME=	sigscheme-0.8.5
CATEGORIES=	lang
MASTER_SITES=	http://sigscheme.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/uim/sigscheme
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

CFLAGS+=		-std=c99

.include "../../devel/libgcroots/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
