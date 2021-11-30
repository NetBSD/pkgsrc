# $NetBSD: Makefile,v 1.51 2021/11/30 16:25:40 ryoon Exp $

DISTNAME=	libexif-0.6.24
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=libexif/}
GITHUB_PROJECT=	libexif
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://libexif.github.io/
COMMENT=	EXIF file library
LICENSE=	gnu-lgpl-v2.1

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake msgfmt msgmerge xgettext
# "error: 'for' loop initial declarations are only allowed in C99 mode"
USE_LANGUAGES=		c99
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		ac_cv_path_DOXYGEN=false
PKGCONFIG_OVERRIDE=	libexif.pc.in

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
