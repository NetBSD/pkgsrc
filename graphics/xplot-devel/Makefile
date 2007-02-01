# $NetBSD: Makefile,v 1.3 2007/02/01 16:08:21 joerg Exp $

DISTNAME=	xplot-0.90.8
PKGREVISION=	1
CATEGORIES=	graphics x11
MASTER_SITES=	http://acert.ir.bbn.com/downloads/acert-geospatial/
HOMEPAGE=	http://www.xplot.org/

MAINTAINER=	gdt@NetBSD.org
COMMENT=	Plotting program (development snapshot)

USE_X11BASE=	yes
GNU_CONFIGURE=	yes

DOCFILES=	ANNOUNCE README README.tcp_plots \
		demo.0 demo.1 demo.2 demo.3 demo.4 demo.5 demo.6 demo.7

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xplot
.for file in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/xplot
.endfor

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
