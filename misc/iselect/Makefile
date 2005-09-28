# $NetBSD: Makefile,v 1.17 2005/09/28 19:51:27 rillig Exp $
#

DISTNAME=		iselect-1.2.0
PKGREVISION=		2
CATEGORIES=		misc
MASTER_SITES=		http://www.engelschall.com/sw/iselect/distrib/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.engelschall.com/sw/iselect/
COMMENT=		Curses based Interactive Selection Tool

GNU_CONFIGURE=		yes

post-configure:
	touch ${WRKSRC}/config_ac.h.in

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
