# $NetBSD: Makefile,v 1.7 2002/10/14 12:54:31 dillo Exp $
#

DISTNAME=		iselect-1.2.0
CATEGORIES=		misc
MASTER_SITES=		http://www.engelschall.com/sw/iselect/distrib/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.engelschall.com/sw/iselect/
COMMENT=		Curses based Interactive Selection Tool

USE_BUILDLINK_ONLY=	# defined
GNU_CONFIGURE=		# defined

post-configure:
	touch ${WRKSRC}/config_ac.h.in

.include "../../devel/ncurses/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
