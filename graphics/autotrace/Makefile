# $NetBSD: Makefile,v 1.28 2006/05/18 20:29:59 wiz Exp $
#

DISTNAME=	autotrace-0.31.1
PKGREVISION=	7
CATEGORIES=	graphics cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=autotrace/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://autotrace.sourceforge.net/
COMMENT=	Convert bitmap to vector graphics

BROKEN_IN=	pkgsrc-2006Q1

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

PKGCONFIG_OVERRIDE=	autotrace.pc.in

.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
