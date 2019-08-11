# $NetBSD: Makefile,v 1.37 2019/08/11 13:21:17 wiz Exp $

DISTNAME=	xplot-0.90.7.1
PKGREVISION=	13
CATEGORIES=	graphics x11
MASTER_SITES=	http://www.xplot.org/xplot/
HOMEPAGE=	http://www.xplot.org/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Plotting program, most often used in conjunction with tcptrace

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
