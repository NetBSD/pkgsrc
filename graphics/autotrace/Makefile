# $NetBSD: Makefile,v 1.6 2001/10/23 13:14:56 jlam Exp $
#

DISTNAME=	autotrace-0.26
CATEGORIES=	graphics cad
MASTER_SITES=	http://homepages.go.com/homepages/m/a/r/martweb/ \
		ftp://autotrace.sourceforge.net/pub/autotrace/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://homepages.go.com/homepages/m/a/r/martweb/AutoTrace.htm
COMMENT=	convert bitmap to vector graphics

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES

.include "../../mk/x11.buildlink.mk"
.include "../../graphics/ImageMagick/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
