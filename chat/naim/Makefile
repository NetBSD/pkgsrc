# $NetBSD: Makefile,v 1.44 2006/03/04 21:29:03 jlam Exp $

DISTNAME=	naim-0.11.8.1
CATEGORIES=	chat
MASTER_SITES=	http://shell.n.ml.org/n/naim/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://site.n.ml.org/info/naim/
COMMENT=	Ncurses-based AIM, ICQ, IRC, and Lily client

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

USE_NCURSES=		# compiles fine, but terminates on startup with:
# assertion "strlen(h->addch.buf) == h->addch.len" failed:
# file "hwprintf.c", line 41, function "h_zero"

#INCOMPAT_CURSES=	NetBSD-1.5* NetBSD-1.6[-_.]*
#INCOMPAT_CURSES+=	NetBSD-1.6[A-Z]-* NetBSD-1.6Z[A-K]*

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
