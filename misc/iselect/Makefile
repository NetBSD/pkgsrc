# $NetBSD: Makefile,v 1.14 2004/04/27 02:24:08 snj Exp $
#

DISTNAME=		iselect-1.2.0
PKGREVISION=		1
CATEGORIES=		misc
MASTER_SITES=		http://www.engelschall.com/sw/iselect/distrib/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.engelschall.com/sw/iselect/
COMMENT=		Curses based Interactive Selection Tool

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		# defined

post-configure:
	touch ${WRKSRC}/config_ac.h.in

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
