# $NetBSD: Makefile,v 1.1.1.1 2002/07/16 15:26:01 wiz Exp $
#

DISTNAME=	ttf2pt1-3.4.0
PKGREVISION=	2
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ttf2pt1/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	reinoud@netbsd.org
HOMEPAGE=	http://ttf2pt1.sourceforge.net
COMMENT=	TrueType font converter to Postscript type 1

DEPENDS+=	t1utils-[0-9]*:../../textproc/t1utils

USE_CONFIG_WRAPPER=	yes

.include "../../graphics/freetype2/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
