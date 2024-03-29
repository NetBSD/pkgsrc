# $NetBSD: Makefile,v 1.61 2023/10/21 17:10:39 gdt Exp $

DISTNAME=	povray-3.6.1
PKGREVISION=	17
CATEGORIES=	graphics
MASTER_SITES=	http://www.povray.org/ftp/pub/povray/Official/Unix/
MASTER_SITES+=	ftp://ftp.povray.org/pub/povray/Official/Unix/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.povray.org/
COMMENT=	Persistence of Vision Ray Tracer
LICENSE=	povray-license

BUILDLINK_API_DEPENDS.zlib+=	zlib>=1.2.1

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-optimiz
CONFIGURE_ARGS+=	--enable-strip
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE}
CONFIGURE_ENV+=		COMPILED_BY="The NetBSD Packages Collection"

.include "../../mk/bsd.prefs.mk"

PLIST_SUBST+=	POVRAY=povray-3.6

PKG_SYSCONFSUBDIR=	povray/3.6
EGDIR=			${PREFIX}/share/examples/povray
CONF_FILES=		${EGDIR}/povray.conf ${PKG_SYSCONFDIR}/povray.conf
CONF_FILES+=		${EGDIR}/povray.ini ${PKG_SYSCONFDIR}/povray.ini

INSTALLATION_DIRS=	share/povray-3.6/scripts

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
