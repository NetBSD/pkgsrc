# $NetBSD: Makefile,v 1.4 1999/07/08 10:49:39 agc Exp $

DISTNAME=	ucblogo-4.6
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU:=ucblogo/}

MAINTAINER=	packages@netbsd.org

MAKEFILE=	makefile
GNU_CONFIGURE=	yes
# otherwise ./configure guesses -L incorrectly
CONFIGURE_ENV+=	LIBS=-L/usr/X11R6/lib
USE_X11=	yes

.include "../../mk/bsd.pkg.mk"
