# $NetBSD: Makefile,v 1.2 2000/12/23 10:55:51 hubertf Exp $
#

DISTNAME=	gaim-0.11.0pre3
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
