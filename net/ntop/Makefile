# $NetBSD: Makefile,v 1.16 2001/01/07 02:25:35 wiz Exp $

DISTNAME=		ntop-1.1
PKGNAME=		ntop-1.1nb1
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.unipi.it/pub/local/ntop/source/
EXTRACT_SUFX=		-src.tar.gz

MAINTAINER=		kim@tac.nyc.ny.us
HOMEPAGE=		http://www.ntop.org/

GNU_CONFIGURE=		yes
USE_CURSES=		yes
REPLACE_NCURSES=	${WRKSRC}/configure ${WRKSRC}/ntop.h
CONFIGURE_ARGS+=	--enable-threads=no

INSTALL_TARGET=		install install-man

.include "../../mk/bsd.prefs.mk"

.if ${NEED_NCURSES} == "YES"
CPPFLAGS+=		-I${LOCALBASE}/include	# for ncurses.h
LDFLAGS+=		-L${LOCALBASE}/lib -Wl,-R${LOCALBASE}/lib
MAKE_ENV+=		CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
.endif

.include "../../mk/bsd.pkg.mk"
