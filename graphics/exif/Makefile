# $NetBSD: Makefile,v 1.15 2005/07/21 16:29:51 wiz Exp $
#

DISTNAME=	exif-0.6.9
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libexif/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://libexif.sourceforge.net/
COMMENT=	Grab Exif information from digital camera images

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes

LIBS+=		${BUILDLINK_LDADD.iconv}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pkg-config/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
