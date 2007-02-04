# $NetBSD: Makefile,v 1.43 2007/02/04 15:26:34 joerg Exp $
#

DISTNAME=	libggi-2.1.1.src
PKGNAME=	${DISTNAME:S/.src//}
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://www.ggi-project.org/ftp/ggi/v2.1/ \
		${MASTER_SITE_SOURCEFORGE:=ggi/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ggi-project.org/
COMMENT=	General Graphics Interface library is a flexible drawing library

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_LIBTOOL=		yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-debug
CONFIGURE_ARGS+=	--with-x
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

PKG_SYSCONFSUBDIR=	ggi
EGDIR=			${PREFIX}/share/examples/ggi
CONF_FILES=		${EGDIR}/libggi.conf ${PKG_SYSCONFDIR}/libggi.conf

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
.if !empty(OS_VERSION:M1.[56].*)
PLIST_SUBST+=	COND_TERMINFO="@comment "
.else
PLIST_SUBST+=	COND_TERMINFO=""
.endif
.else
PLIST_SUBST+=	COND_TERMINFO=""
.endif

.if ${OPSYS} == "DragonFly" || ${OPSYS} == "FreeBSD"
PLIST_SUBST+=	COND_LIBVGL=""
.else
PLIST_SUBST+=	COND_LIBVGL="@comment "
.endif

.if ${X11_TYPE} == "modular"
.include "../../x11/libXxf86dga/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
PLIST_SUBST+=	COND_XF86DGA=""
.elif exists(${X11BASE}/include/X11/extensions/xf86dga.h)
PLIST_SUBST+=	COND_XF86DGA=""
.else
PLIST_SUBST+=	COND_XF86DGA="@comment "
.endif

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../devel/ncurses/buildlink3.mk"
.include "../../graphics/libgii/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
