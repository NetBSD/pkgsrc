# $NetBSD: Makefile,v 1.14 2022/06/28 11:34:48 wiz Exp $

DISTNAME=	libcdio-paranoia-10.2+2.0.1
PKGNAME=	libcdio-paranoia-2.0.1
PKGREVISION=	3
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNU:=libcdio/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/libcdio/
COMMENT=	CD-ROM access library: CDDA support
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake perl:run pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-versioned-libs
INFO_FILES=		yes
PKGCONFIG_OVERRIDE+=	libcdio_cdda.pc.in
PKGCONFIG_OVERRIDE+=	libcdio_paranoia.pc.in
TEST_TARGET=		check

.include "../../converters/libiconv/buildlink3.mk"
.include "../../misc/libcdio/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
