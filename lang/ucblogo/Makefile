# $NetBSD: Makefile,v 1.8 2002/07/10 19:44:25 nathanw Exp $

DISTNAME=	ucblogo-4.6
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU:=non-gnu/ucblogo/}

MAINTAINER=	packages@netbsd.org
COMMENT=	Brian Harvey's logo language interpreter

MAKEFILE=	makefile
GNU_CONFIGURE=	yes
# otherwise ./configure guesses -L incorrectly
LIBS=		-L${X11BASE}/lib
USE_X11=	yes

.include "../../mk/bsd.pkg.mk"
