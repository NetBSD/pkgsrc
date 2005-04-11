# $NetBSD: Makefile,v 1.16 2005/04/11 21:46:35 tv Exp $
#

DISTNAME=		iselect-1.2.0
PKGREVISION=		2
CATEGORIES=		misc
MASTER_SITES=		http://www.engelschall.com/sw/iselect/distrib/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.engelschall.com/sw/iselect/
COMMENT=		Curses based Interactive Selection Tool

GNU_CONFIGURE=		# defined

post-configure:
	touch ${WRKSRC}/config_ac.h.in

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
