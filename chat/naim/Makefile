# $NetBSD: Makefile,v 1.32 2004/04/15 09:17:30 wiz Exp $

DISTNAME=	naim-0.11.6.7
CATEGORIES=	chat
MASTER_SITES=	http://shell.n.ml.org/n/naim/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	snj@NetBSD.org
HOMEPAGE=	http://site.n.ml.org/info/naim/
COMMENT=	Ncurses-based AIM, ICQ, IRC and Lily client

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	--mandir=${PREFIX}/man

INCOMPAT_CURSES=	NetBSD-1.5* NetBSD-1.6[-_.]*
INCOMPAT_CURSES+=	NetBSD-1.6[A-Z]-* NetBSD-1.6Z[A-K]*

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
