# $NetBSD: Makefile,v 1.16 2002/10/28 13:38:14 wiz Exp $
#

DISTNAME=	gnuplot-3.7.1
PKGREVISION=	1
SVR4_PKGNAME=	gplot
CATEGORIES=	graphics x11
MASTER_SITES=	ftp://ftp.gnuplot.vt.edu/pub/gnuplot/ \
		ftp://ftp.ucc.ie/pub/gnuplot/

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://www.cs.dartmouth.edu/gnuplot_info.html
COMMENT=	gnuplot is a nice plotting utility

USE_BUILDLINK2=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--with-png

.include "../../graphics/png/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
