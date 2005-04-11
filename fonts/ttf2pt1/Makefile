# $NetBSD: Makefile,v 1.10 2005/04/11 21:45:47 tv Exp $
#

DISTNAME=	ttf2pt1-3.4.4
PKGREVISION=	1
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ttf2pt1/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	reinoud@NetBSD.org
HOMEPAGE=	http://ttf2pt1.sourceforge.net/
COMMENT=	TrueType font converter to Postscript type 1

DEPENDS+=	t1utils-[0-9]*:../../fonts/t1utils


.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
