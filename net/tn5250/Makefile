# $NetBSD: Makefile,v 1.6 2001/06/11 06:34:47 jlam Exp $
#

DISTNAME=	tn5250-0.12.51
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.blarg.net/users/mmadore/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.linux-sna.org/software/5250/
COMMENT=	Implementation of the IBM 5250 telnet protocol

GNU_CONFIGURE=		YES
USE_CURSES=		YES
REPLACE_NCURSES=	${WRKSRC}/cursesterm.cc ${WRKSRC}/configure

.include "../../mk/bsd.prefs.mk"

.if ${NEED_NCURSES} == "YES"
CPPFLAGS+=		-I${LOCALBASE}/include
.endif

.include "../../mk/bsd.pkg.mk"
