# $NetBSD: Makefile,v 1.11 2000/01/15 18:46:32 jlam Exp $

DISTNAME=		ntop-1.0
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.unipi.it/pub/local/ntop/source/
EXTRACT_SUFX=		.src.tar.gz

MAINTAINER=		kim@tac.nyc.ny.us
HOMEPAGE=		http://www-serra.unipi.it/~ntop/

BUILD_DEPENDS+=		${LOCALBASE}/bin/autoconf:../../devel/autoconf
DEPENDS+=		ncurses>=4.2:../../devel/ncurses

HAS_CONFIGURE=		yes
GNU_CONFIGURE=		yes

CPPFLAGS+=		-I${LOCALBASE}/include	# for ncurses.h
LDFLAGS+=		-L${LOCALBASE}/lib	# for -lncurses
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"

pre-configure:
	cd ${WRKSRC}; ${LOCALBASE}/bin/autoconf

.include "../../mk/bsd.pkg.mk"
