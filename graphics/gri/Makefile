# $NetBSD: Makefile,v 1.16 2004/04/24 23:19:43 snj Exp $

DISTNAME=		gri-2.12.5
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gri/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://gri.sourceforge.net/
COMMENT=		Language for scientific graphics applications

BUILD_DEPENDS+=		ImageMagick-[0-9]*:../../graphics/ImageMagick

GNU_CONFIGURE=		yes
USE_X11=		yes
USE_GNU_TOOLS+=		make
USE_BUILDLINK3=	 	yes
USE_PERL5=		build
REPLACE_PERL=		gri_merge gri_unpage

USE_MAKEINFO=		yes
INFO_FILES=		gri.info

.include "../../devel/netcdf/buildlink3.mk"
.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
