# $NetBSD: Makefile,v 1.53 2024/08/05 08:07:00 tnn Exp $

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
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		ac_cv_path_DOXYGEN=false
PKGCONFIG_OVERRIDE=	libexif.pc.in

# "error: 'for' loop initial declarations are only allowed in C99 mode"
FORCE_C_STD=		c99

# 199506L for localtime_r, but has to be at least 200112L with C99
CPPFLAGS+=	-D_POSIX_C_SOURCE=200112L

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
