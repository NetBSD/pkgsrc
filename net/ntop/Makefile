# $NetBSD: Makefile,v 1.18 2001/06/11 06:34:46 jlam Exp $

DISTNAME=		ntop-1.1
PKGNAME=		ntop-1.1nb1
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.unipi.it/pub/local/ntop/source/
EXTRACT_SUFX=		-src.tar.gz

MAINTAINER=		kim@tac.nyc.ny.us
HOMEPAGE=		http://www.ntop.org/
COMMENT=		shows network usage (similar to "top" for processes)

GNU_CONFIGURE=		yes
USE_CURSES=		yes
REPLACE_NCURSES=	${WRKSRC}/configure ${WRKSRC}/ntop.h
CONFIGURE_ARGS+=	--enable-threads=no

INSTALL_TARGET=		install install-man

.include "../../mk/bsd.prefs.mk"

.if ${NEED_NCURSES} == "YES"
CPPFLAGS+=		-I${LOCALBASE}/include	# for ncurses.h
LDFLAGS+=		-L${LOCALBASE}/lib -Wl,-R${LOCALBASE}/lib
.endif

.include "../../mk/bsd.pkg.mk"
