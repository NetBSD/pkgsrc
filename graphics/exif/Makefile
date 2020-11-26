# $NetBSD: Makefile,v 1.29 2020/11/26 15:44:27 nia Exp $

DISTNAME=	exif-0.6.22
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=libexif/}
GITHUB_RELEASE=	exif-${PKGVERSION_NOREV:S/./_/g}-release
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://libexif.github.io/
COMMENT=	Grab Exif information from digital camera images
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=		pkg-config
USE_TOOLS+=		msgfmt msgmerge xgettext
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

LIBS+=		${BUILDLINK_LDADD.iconv}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
