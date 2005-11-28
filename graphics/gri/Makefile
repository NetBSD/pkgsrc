# $NetBSD: Makefile,v 1.22 2005/11/28 06:41:20 jlam Exp $

DISTNAME=		gri-2.12.5
PKGREVISION=	1
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gri/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://gri.sourceforge.net/
COMMENT=		Language for scientific graphics applications

BUILD_DEPENDS+=		ImageMagick-[0-9]*:../../graphics/ImageMagick

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake gs:run perl
REPLACE_PERL=		gri_merge gri_unpage

USE_MAKEINFO=		yes
INFO_FILES=		gri.info

.include "../../devel/netcdf/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
