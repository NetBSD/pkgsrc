# $NetBSD: Makefile,v 1.10 1999/07/06 08:06:29 jlam Exp $

DISTNAME=		ntop-1.0
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.unipi.it/pub/local/ntop/source/
EXTRACT_SUFX=		.src.tar.gz

MAINTAINER=		kim@tac.nyc.ny.us
HOMEPAGE=		http://www-serra.unipi.it/~ntop/

BUILD_DEPENDS+=		autoconf:../../devel/autoconf
DEPENDS+=		ncurses-4.2:../../devel/ncurses

HAS_CONFIGURE=		yes
GNU_CONFIGURE=		yes

CPPFLAGS+=		-I${LOCALBASE}/include	# for ncurses.h
LDFLAGS+=		-L${LOCALBASE}/lib	# for -lncurses
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"

pre-configure:
	( cd ${WRKSRC}; autoconf )

.include "../../mk/bsd.pkg.mk"
