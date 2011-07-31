# $NetBSD: Makefile,v 1.48 2011/07/31 17:58:09 jakllsch Exp $

DISTNAME=	povray-3.6.1
PKGREVISION=	10
CATEGORIES=	graphics
MASTER_SITES=	http://www.povray.org/ftp/pub/povray/Official/Unix/ \
		ftp://ftp.povray.org/pub/povray/Official/Unix/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.povray.org/
COMMENT=	Persistence of Vision Ray Tracer
LICENSE=	povray-license

PKG_DESTDIR_SUPPORT=	user-destdir

BUILDLINK_API_DEPENDS.zlib+=	zlib>=1.2.1

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-optimiz
CONFIGURE_ARGS+=	--enable-strip
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ENV+=		COMPILED_BY="The NetBSD Packages Collection"
CPPFLAGS+=		-I${BUILDLINK_PREFIX.png12}/include/libpng12

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == x86_64
GCC_REQD+=	3.4
.endif

PLIST_SUBST+=	POVRAY=povray-3.6

EGDIR=		${PREFIX}/share/examples/povray
CONF_FILES=	${EGDIR}/povray.conf ${PKG_SYSCONFDIR}/povray.conf
CONF_FILES+=	${EGDIR}/povray.ini ${PKG_SYSCONFDIR}/povray.ini

INSTALLATION_DIRS=	share/povray-3.6/scripts

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png12/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
