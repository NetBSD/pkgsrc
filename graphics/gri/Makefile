# $NetBSD: Makefile,v 1.8 2003/07/03 16:24:28 seb Exp $

DISTNAME=		gri-2.8.7
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gri/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		tech-pkg@netbsd.org
HOMEPAGE=		http://gri.sourceforge.net
COMMENT=		language for scientific graphics applications

BUILD_DEPENDS+=		ImageMagick-[0-9]*:../../graphics/ImageMagick

GNU_CONFIGURE=		# defined
USE_X11=		# defined
USE_GMAKE=		# defined
USE_BUILDLINK2=	 	# defined
INFO_FILES=		gri.info
USE_PERL5=		build
REPLACE_PERL=		gri_merge gri_unpage

USE_NEW_TEXINFO=	YES
USE_MAKEINFO=	YES
INFO_FILES=	gri.info

.include "../../devel/netcdf/buildlink2.mk"
.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
