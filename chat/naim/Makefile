# $NetBSD: Makefile,v 1.29 2004/02/13 22:15:32 snj Exp $
#

DISTNAME=	naim-0.11.6.6
CATEGORIES=	chat
MASTER_SITES=	http://shell.n.ml.org/n/naim/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	snj@NetBSD.org
HOMEPAGE=	http://site.n.ml.org/info/naim/
COMMENT=	Ncurses-based AIM, ICQ, IRC and Lily client

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
USE_NCURSES=		# assertion "COLOR_PAIRS >= (COLORS*COLORS)" failed: file "./win.c", line 250, function "wsetup_colors"

CONFIGURE_ARGS+=	--mandir=${PREFIX}/man

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
