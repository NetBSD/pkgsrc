# $NetBSD: Makefile,v 1.23 2003/09/27 17:07:35 grant Exp $
#

DISTNAME=	naim-0.11.6.1
CATEGORIES=	chat
MASTER_SITES=	http://shell.n.ml.org/n/naim/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://site.n.ml.org/info/naim/
COMMENT=	Ncurses-based AIM, ICQ, IRC and Lily client

GNU_CONFIGURE=	YES

USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
USE_NCURSES=		# assertion "COLOR_PAIRS >= (COLORS*COLORS)" failed: file "./win.c", line 250, function "wsetup_colors"

.include "../../mk/curses.buildlink2.mk"
.include "../../devel/readline/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
