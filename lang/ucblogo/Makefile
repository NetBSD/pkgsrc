# $NetBSD: Makefile,v 1.5 2000/01/10 00:17:57 wiz Exp $

DISTNAME=	ucblogo-4.6
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU:=ucblogo/}

MAINTAINER=	packages@netbsd.org

MAKEFILE=	makefile
GNU_CONFIGURE=	yes
# otherwise ./configure guesses -L incorrectly
CONFIGURE_ENV+=	LIBS=-L${X11BASE}/lib
USE_X11=	yes

.include "../../mk/bsd.pkg.mk"
