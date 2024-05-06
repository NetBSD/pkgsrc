# $NetBSD: Makefile,v 1.62 2024/05/06 08:40:27 jperkin Exp $

DISTNAME=	libggi-2.2.2.src
PKGNAME=	${DISTNAME:S/.src//}
PKGREVISION=	5
CATEGORIES=	graphics
#MASTER_SITES=	http://www.ggi-project.org/ftp/ggi/v2.2/
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ggi/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.ggi-project.org/
HOMEPAGE=	https://ibiblio.org/ggicore/
COMMENT=	General Graphics Interface library is a flexible drawing library

MAKE_JOBS_SAFE=		no

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_LIBTOOL=		yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-debug
CONFIGURE_ARGS+=	--with-x
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

PKG_SYSCONFSUBDIR=	ggi
EGDIR=			${PREFIX}/share/examples/ggi
CONF_FILES=		${EGDIR}/libggi.conf ${PKG_SYSCONFDIR}/libggi.conf

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
CONF_FILES+=	${EGDIR}/fbdev.conf ${PKG_SYSCONFDIR}/ggi/ggi/targets/fbdev.conf
.endif

PLIST_VARS+=		libvgl xf86dga

.if ${OPSYS} == "DragonFly" || ${OPSYS} == "FreeBSD"
PLIST.libvgl=		yes
.endif

.if ${X11_TYPE} == "modular" || \
	exists(${X11BASE}/include/X11/extensions/xf86dga.h)
.include "../../x11/libXxf86dga/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
PLIST.xf86dga=		yes
.endif

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../devel/ncurses/buildlink3.mk"
.include "../../graphics/libgii/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
