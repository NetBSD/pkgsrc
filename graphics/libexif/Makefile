# $NetBSD: Makefile,v 1.48 2020/05/19 11:20:00 nia Exp $

DISTNAME=	libexif-0.6.22
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=libexif/}
GITHUB_PROJECT=	libexif
GITHUB_RELEASE=	${DISTNAME:S/./_/g}-release
EXTRACT_SUFX=	.tar.xz

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

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
