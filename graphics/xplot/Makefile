# $NetBSD: Makefile,v 1.23 2006/10/14 09:13:14 bad Exp $

DISTNAME=	xplot-0.90.7.1
PKGREVISION=	5
CATEGORIES=	graphics x11
MASTER_SITES=	http://www.xplot.org/xplot/
HOMEPAGE=	http://www.xplot.org/

MAINTAINER=	dan@NetBSD.org
COMMENT=	Plotting program, most often used in conjunction with tcptrace

USE_X11BASE=	yes
GNU_CONFIGURE=	yes

DOCFILES=	ANNOUNCE README README.tcp_plots
# demo.? removed from interim .7.1 version
#		demo.0 demo.1 demo.2 demo.3 demo.4 demo.5 demo.6 demo.7

.include "../../mk/x11.buildlink3.mk"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xplot
.for file in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/xplot
.endfor

.include "../../mk/bsd.pkg.mk"
