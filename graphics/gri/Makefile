# $NetBSD: Makefile,v 1.4 2002/10/02 21:38:01 dillo Exp $

DISTNAME=		gri-2.8.7
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gri/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://gri.sourceforge.net
COMMENT=		language for scientific graphics applications

BUILD_DEPENDS+=		ImageMagick-[0-9]*:../../graphics/ImageMagick

GNU_CONFIGURE=		# defined
USE_X11=		# defined
USE_GMAKE=		# defined
USE_BUILDLINK_ONLY= 	# defined
INFO_FILES=		gri.info
USE_PERL5=		build
REPLACE_PERL=		${WRKSRC}/gri_merge ${WRKSRC}/gri_unpage

.include "../../devel/netcdf/buildlink.mk"
.include "../../mk/ghostscript.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
