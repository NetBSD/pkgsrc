# $NetBSD: Makefile,v 1.9 1999/05/26 22:37:58 tron Exp $

DISTNAME=		ntop-1.0
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.unipi.it/pub/local/ntop/source/
EXTRACT_SUFX=		.src.tar.gz

MAINTAINER=		kim@tac.nyc.ny.us

BUILD_DEPENDS=		autoconf:../../devel/autoconf
DEPENDS=		ncurses-1.9.9g:../../devel/ncurses

HOMEPAGE=		http://www-serra.unipi.it/~ntop/

NOT_FOR_PLATFORM=	*-*-alpha *-*-mips	# elf problems WRT libcurses

HAS_CONFIGURE=		yes
GNU_CONFIGURE=		yes

CFLAGS+=		-I${PREFIX}/include
LDFLAGS+=		-L${PREFIX}/lib

CONFIGURE_ENV+=		CPPFLAGS=-I${PREFIX}/include
CONFIGURE_ENV+=		CFLAGS=-I${PREFIX}/include
CONFIGURE_ENV+=		LDFLAGS=-L${PREFIX}/lib

pre-configure:
	(cd ${WRKSRC}; autoconf)

.include "../../mk/bsd.pkg.mk"
