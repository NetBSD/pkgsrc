# $NetBSD: Makefile,v 1.8 2002/10/25 17:53:43 wiz Exp $
#

DISTNAME=		iselect-1.2.0
CATEGORIES=		misc
MASTER_SITES=		http://www.engelschall.com/sw/iselect/distrib/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.engelschall.com/sw/iselect/
COMMENT=		Curses based Interactive Selection Tool

USE_BUILDLINK2=		# defined
GNU_CONFIGURE=		# defined

post-configure:
	touch ${WRKSRC}/config_ac.h.in

.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
