# $NetBSD: Makefile,v 1.10 2002/09/22 00:08:19 jlam Exp $
#

DISTNAME=	autotrace-0.29
PKGREVISION=	1
CATEGORIES=	graphics cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=autotrace/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://autotrace.sourceforge.net/
COMMENT=	convert bitmap to vector graphics

USE_BUILDLINK2=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES

.include "../../graphics/ImageMagick/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
