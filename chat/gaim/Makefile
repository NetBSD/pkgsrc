# $NetBSD: Makefile,v 1.7 2001/06/11 06:34:21 jlam Exp $
#

DISTNAME=	gaim-0.11.0pre11
CATEGORIES=	x11 chat
MASTER_SITES=	ftp://ftp.marko.net/pub/gaim/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.marko.net/gaim/
COMMENT=	gtk-based client for AOL's Instant Messenger chat system

DEPENDS+=	gtk+>=1.2.3:../../x11/gtk
DEPENDS+=	esound>=0.2.7:../../audio/esound

USE_GMAKE=	YES
USE_LIBINTL=	YES
USE_X11BASE=	YES
GNU_CONFIGURE=	YES

# for pthread.h
CPPFLAGS+=	-I${LOCALBASE}/include

.include "../../mk/bsd.pkg.mk"
