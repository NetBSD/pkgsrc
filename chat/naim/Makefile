# $NetBSD: Makefile,v 1.48 2008/04/23 21:37:15 wiz Exp $

DISTNAME=	naim-0.11.8.3.1
CATEGORIES=	chat
MASTER_SITES=	http://naim.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://naim.n.ml.org/about
COMMENT=	Ncurses-based AIM, ICQ, IRC, and Lily client

GNU_CONFIGURE=		yes
MAKE_JOBS_SAFE=		no
USE_LIBTOOL=		yes

USE_NCURSES=		# compiles fine, but terminates on startup with:
# assertion "strlen(h->addch.buf) == h->addch.len" failed:
# file "hwprintf.c", line 41, function "h_zero"

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
