# $NetBSD: Makefile,v 1.7 2001/06/12 20:33:04 jlam Exp $

DISTNAME=	ucblogo-4.6
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU:=ucblogo/}

MAINTAINER=	packages@netbsd.org
COMMENT=	Brian Harvey's logo language interpreter

MAKEFILE=	makefile
GNU_CONFIGURE=	yes
# otherwise ./configure guesses -L incorrectly
LIBS=		-L${X11BASE}/lib
USE_X11=	yes

.include "../../mk/bsd.pkg.mk"
