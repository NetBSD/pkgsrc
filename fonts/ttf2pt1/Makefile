# $NetBSD: Makefile,v 1.6 2003/12/30 17:21:55 cjep Exp $
#

DISTNAME=	ttf2pt1-3.4.0
PKGREVISION=	3
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ttf2pt1/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	reinoud@NetBSD.org
HOMEPAGE=	http://ttf2pt1.sourceforge.net/
COMMENT=	TrueType font converter to Postscript type 1

DEPENDS+=	t1utils-[0-9]*:../../fonts/t1utils

USE_BUILDLINK2=	# defined

.include "../../graphics/freetype2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
