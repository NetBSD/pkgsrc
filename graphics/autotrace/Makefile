# $NetBSD: Makefile,v 1.5 2001/08/29 22:41:15 jlam Exp $
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

.include "../../graphics/ImageMagick/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
