# $NetBSD: Makefile,v 1.13 2003/09/28 09:13:58 jlam Exp $
#

DISTNAME=		iselect-1.2.0
PKGREVISION=		1
CATEGORIES=		misc
MASTER_SITES=		http://www.engelschall.com/sw/iselect/distrib/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.engelschall.com/sw/iselect/
COMMENT=		Curses based Interactive Selection Tool

USE_BUILDLINK2=		# defined
GNU_CONFIGURE=		# defined

post-configure:
	touch ${WRKSRC}/config_ac.h.in

.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
