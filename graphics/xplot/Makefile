# $NetBSD: Makefile,v 1.11 1999/04/13 15:31:05 agc Exp $
#

DISTNAME=	xplot-0.90
CATEGORIES=	graphics x11
MASTER_SITES=	ftp://mercury.lcs.mit.edu/pub/shep/

MAINTAINER=	thorpej@netbsd.org

USE_X11BASE=	yes
GNU_CONFIGURE=	yes

DOCFILES=	ANNOUNCE README README.tcp_plots demo.0 demo.1 demo.2 \
		demo.3 demo.4 demo.5 demo.6 demo.7

post-install:
	${MKDIR} ${PREFIX}/share/doc/xplot
.for file in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/xplot
.endfor

.include "../../mk/bsd.pkg.mk"
