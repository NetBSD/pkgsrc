# $NetBSD: Makefile,v 1.10 1999/06/10 15:23:10 hubertf Exp $
#

DISTNAME=	gnuplot-3.7
CATEGORIES=	graphics x11
MASTER_SITES=	ftp://ftp.gnuplot.vt.edu/pub/gnuplot/ \
		ftp://ftp.ucc.ie/pub/gnuplot/

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://www.cs.dartmouth.edu/gnuplot_info.html

USE_X11=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --without-gd --without-png --without-plot --with-x

.include "../../mk/bsd.pkg.mk"
