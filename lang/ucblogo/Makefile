# $NetBSD: Makefile,v 1.12 2004/10/03 00:15:03 tv Exp $

DISTNAME=	ucblogo-5.3
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.cs.berkeley.edu/pub/ucblogo/
# Not at GNU mirrors yet
# ${MASTER_SITE_GNU:=non-gnu/ucblogo/} \

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://http.cs.berkeley.edu/~bh/logo.html
COMMENT=	Brian Harvey's logo language interpreter

USE_BUILDLINK3= yes
MAKEFILE=	makefile
GNU_CONFIGURE=	yes
# otherwise ./configure guesses -L incorrectly
LIBS=		-L${X11BASE}/lib
USE_X11=	yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ucblogo
	${INSTALL_DATA}	${WRKSRC}/usermanual ${PREFIX}/share/doc/ucblogo/usermanual.txt
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ucblogo/html
	${CP} ${WRKSRC}/emacs/docs/*.html ${PREFIX}/share/doc/ucblogo/html/

.include "../../devel/ncurses/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
