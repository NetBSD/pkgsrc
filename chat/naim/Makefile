# $NetBSD: Makefile,v 1.21 2003/07/25 10:13:04 wiz Exp $
#

DISTNAME=	naim-0.11.6
CATEGORIES=	chat
MASTER_SITES=	http://shell.n.ml.org/n/naim/

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://site.rpi-acm.org/info/naim/
COMMENT=	Ncurses-based AIM/IRC client

GNU_CONFIGURE=	YES

USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
USE_NCURSES=		# assertion "COLOR_PAIRS >= (COLORS*COLORS)" failed: file "./win.c", line 250, function "wsetup_colors"

.include "../../devel/ncurses/buildlink2.mk"
.include "../../devel/readline/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
