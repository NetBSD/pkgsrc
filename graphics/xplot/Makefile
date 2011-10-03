# $NetBSD: Makefile,v 1.27 2011/10/03 01:17:49 dholland Exp $

DISTNAME=	xplot-0.90.7.1
PKGREVISION=	6
CATEGORIES=	graphics x11
MASTER_SITES=	http://www.xplot.org/xplot/
HOMEPAGE=	http://www.xplot.org/

MAINTAINER=	dan@NetBSD.org
COMMENT=	Plotting program, most often used in conjunction with tcptrace

PKG_DESTDIR_SUPPORT=	user-destdir

USE_X11BASE=	yes
GNU_CONFIGURE=	yes

REPLACE_PERL+=	tcpdump2xplot.pl
USE_TOOLS+=	perl:run

DOCFILES=	ANNOUNCE README README.tcp_plots
# demo.? removed from interim .7.1 version
#		demo.0 demo.1 demo.2 demo.3 demo.4 demo.5 demo.6 demo.7

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/xplot
.for file in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DESTDIR}${PREFIX}/share/doc/xplot
.endfor

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
