# $NetBSD: Makefile,v 1.1.1.1 2000/12/15 00:36:27 wiz Exp $
#

DISTNAME=	gaim-0.9.19
CATEGORIES=	x11 chat
MASTER_SITES=	ftp://ftp.marko.net/pub/gaim/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.marko.net/gaim/

DEPENDS+=	gtk+>=1.2.3:../../x11/gtk
DEPENDS+=	esound>=0.2.7:../../audio/esound

USE_X11BASE=	YES
USE_GMAKE=	YES
GNU_CONFIGURE=  yes

# for pthread.h
CONFIGURE_ENV+=	CPPFLAGS=-I${LOCALBASE}/include

.include "../../mk/bsd.pkg.mk"
