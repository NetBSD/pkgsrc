# $NetBSD: Makefile,v 1.48 2010/01/30 15:19:26 tnn Exp $
#

DISTNAME=	libggi-2.2.2.src
PKGNAME=	${DISTNAME:S/.src//}
CATEGORIES=	graphics
MASTER_SITES=	http://www.ggi-project.org/ftp/ggi/v2.1/ \
		${MASTER_SITE_SOURCEFORGE:=ggi/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ggi-project.org/
COMMENT=	General Graphics Interface library is a flexible drawing library

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no

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

PLIST_VARS+=		libvgl terminfo xf86dga

.if ${OPSYS} == "NetBSD"
.  if empty(OS_VERSION:M1.[56].*)
PLIST.terminfo=		yes
.  endif
.else
PLIST.terminfo=		yes
.endif

.if ${OPSYS} == "DragonFly" || ${OPSYS} == "FreeBSD"
PLIST.libvgl=		yes
.endif

.if ${X11_TYPE} == "modular"
.include "../../x11/libXxf86dga/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
PLIST_SUBST+=	COND_XF86DGA=""
PLIST.xf86dga=		yes
.elif exists(${X11BASE}/include/X11/extensions/xf86dga.h)
PLIST.xf86dga=		yes
.endif

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../devel/ncurses/buildlink3.mk"
.include "../../graphics/libgii/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
