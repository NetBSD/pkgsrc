# $NetBSD: Makefile,v 1.3 2001/02/16 15:22:15 wiz Exp $
#

DISTNAME=	autotrace-0.26
CATEGORIES=	graphics cad
MASTER_SITES=	http://homepages.go.com/homepages/m/a/r/martweb/ \
		ftp://autotrace.sourceforge.net/pub/autotrace/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://homepages.go.com/homepages/m/a/r/martweb/AutoTrace.htm
COMMENT=	convert bitmap to vector graphics

DEPENDS+=	ImageMagick>=5.2.8:../../graphics/ImageMagick

GNU_CONFIGURE=	YES
USE_X11=	YES

.include "../../mk/bsd.pkg.mk"
