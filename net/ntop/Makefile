# $NetBSD: Makefile,v 1.14 2000/10/21 02:45:45 mycroft Exp $

DISTNAME=		ntop-1.1
PKGNAME=		ntop-1.1nb1
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.unipi.it/pub/local/ntop/source/
EXTRACT_SUFX=		-src.tar.gz

MAINTAINER=		kim@tac.nyc.ny.us
HOMEPAGE=		http://www-serra.unipi.it/~ntop/

DEPENDS+=		ncurses>=4.2:../../devel/ncurses

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-threads=no

CPPFLAGS+=		-I${LOCALBASE}/include	# for ncurses.h
LDFLAGS+=		-L${LOCALBASE}/lib -Wl,-R${LOCALBASE}/lib
MAKE_ENV+=		CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

INSTALL_TARGET=		install install-man

.include "../../mk/bsd.pkg.mk"
