# $NetBSD: Makefile,v 1.19 2006/03/04 21:30:11 jlam Exp $
#

DISTNAME=		iselect-1.2.0
PKGREVISION=		2
CATEGORIES=		misc
MASTER_SITES=		http://www.engelschall.com/sw/iselect/distrib/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.engelschall.com/sw/iselect/
COMMENT=		Curses based Interactive Selection Tool

GNU_CONFIGURE=		yes

post-configure:
	${TOUCH} ${WRKSRC}/config_ac.h.in

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
