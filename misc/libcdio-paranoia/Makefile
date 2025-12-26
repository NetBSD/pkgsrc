# $NetBSD: Makefile,v 1.16 2025/12/26 11:10:46 adam Exp $

DISTNAME=	libcdio-paranoia-10.2+2.0.2
PKGNAME=	libcdio-paranoia-2.0.2
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=libcdio/}
GITHUB_RELEASE=	release-10.2+2.0.2
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/libcdio/libcdio-paranoia
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

.include "../../mk/compiler.mk"

.if ${CC_VERSION:Mgcc-*} || ${CC_VERSION:Mclang-*}
CPPFLAGS.SunOS+=	-Dalloca=__builtin_alloca
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../misc/libcdio/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
