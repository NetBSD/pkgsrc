# $NetBSD: Makefile,v 1.13 2001/10/18 15:20:21 veego Exp $
#

DISTNAME=	gnuplot-3.7.1
SVR4_PKGNAME=	gplot
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
