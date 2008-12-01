# $NetBSD: Makefile,v 1.41 2008/12/01 12:01:18 obache Exp $

DISTNAME=	povray-3.6.1
PKGREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	http://www.povray.org/ftp/pub/povray/Official/Unix/ \
		ftp://ftp.povray.org/pub/povray/Official/Unix/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.povray.org/
COMMENT=	Persistence of Vision Ray Tracer

PKG_DESTDIR_SUPPORT=	user-destdir

LICENSE=	povray-license

BUILDLINK_API_DEPENDS.zlib+=	zlib>=1.2.1

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-optimiz
CONFIGURE_ARGS+=	--enable-strip
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ENV+=		COMPILED_BY="The NetBSD Packages Collection"

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
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
