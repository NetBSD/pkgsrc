# $NetBSD: Makefile,v 1.6 2002/10/02 19:45:09 dillo Exp $
#

DISTNAME=		iselect-1.2.0
CATEGORIES=		misc
MASTER_SITES=		http://www.engelschall.com/sw/iselect/distrib/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.engelschall.com/sw/iselect/
COMMENT=		Curses based Interactive Selection Tool

BUILD_DEPENDS+=		autoconf>=2.13:../../devel/autoconf

USE_BUILDLINK_ONLY=	# defined
GNU_CONFIGURE=		# defined

post-configure:
	touch ${WRKSRC}/config_ac.h.in

.include "../../devel/ncurses/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
