# $NetBSD: Makefile,v 1.17 2006/02/05 23:09:29 joerg Exp $
#

DISTNAME=	exif-0.6.9
PKGREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libexif/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://libexif.sourceforge.net/
COMMENT=	Grab Exif information from digital camera images

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes

LIBS+=		${BUILDLINK_LDADD.iconv}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
