# $NetBSD: Makefile,v 1.12 2001/03/19 22:11:14 wennmach Exp $
#

DISTNAME=	gnuplot-3.7.1
CATEGORIES=	graphics x11
MASTER_SITES=	ftp://ftp.gnuplot.vt.edu/pub/gnuplot/ \
		ftp://ftp.ucc.ie/pub/gnuplot/

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://www.cs.dartmouth.edu/gnuplot_info.html
COMMENT=	gnuplot is a nice plotting utility

USE_X11=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --without-gd --without-png --without-plot --with-x

.include "../../mk/bsd.pkg.mk"
