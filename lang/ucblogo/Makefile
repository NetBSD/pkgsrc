# $NetBSD: Makefile,v 1.10 2003/07/17 21:45:35 grant Exp $

DISTNAME=	ucblogo-4.6
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU:=non-gnu/ucblogo/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Brian Harvey's logo language interpreter

MAKEFILE=	makefile
GNU_CONFIGURE=	yes
# otherwise ./configure guesses -L incorrectly
LIBS=		-L${X11BASE}/lib
USE_X11=	yes

.include "../../mk/bsd.pkg.mk"
