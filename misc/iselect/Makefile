# $NetBSD: Makefile,v 1.9 2003/06/02 01:18:15 jschauma Exp $
#

DISTNAME=		iselect-1.2.0
CATEGORIES=		misc
MASTER_SITES=		http://www.engelschall.com/sw/iselect/distrib/

MAINTAINER=		tech-pkg@netbsd.org
HOMEPAGE=		http://www.engelschall.com/sw/iselect/
COMMENT=		Curses based Interactive Selection Tool

USE_BUILDLINK2=		# defined
GNU_CONFIGURE=		# defined

post-configure:
	touch ${WRKSRC}/config_ac.h.in

.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
