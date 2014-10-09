# $NetBSD: Makefile,v 1.43 2014/10/09 14:06:36 wiz Exp $

DISTNAME=	libexif-0.6.21
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libexif/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://libexif.sourceforge.net/
COMMENT=	EXIF file library
LICENSE=	gnu-lgpl-v2.1

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		ac_cv_path_DOXYGEN=false
PKGCONFIG_OVERRIDE=	libexif.pc.in

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
