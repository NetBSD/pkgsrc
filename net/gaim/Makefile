# $NetBSD: Makefile,v 1.10 2000/01/07 01:30:45 garbled Exp $
#

DISTNAME=	gaim-0.9.10
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.marko.net/pub/gaim/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.marko.net/gaim/

DEPENDS+=	gtk+>=1.2.3:../../x11/gtk
DEPENDS+=	esound>=0.2.7:../../audio/esound

USE_X11BASE=	YES
USE_GMAKE=	YES
GNU_CONFIGURE=  yes

.include "../../mk/bsd.pkg.mk"
