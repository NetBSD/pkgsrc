# $NetBSD: Makefile,v 1.31 2004/10/03 00:14:55 tv Exp $
#

DISTNAME=	libggi-2.0.6.src
PKGNAME=	${DISTNAME:S/.src//}
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.ggi-project.org/pub/packages/ggi \
		http://www.ggi-project.org/ftp/ggi/v2.0/ \
		${MASTER_SITE_SOURCEFORGE:=ggi/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://www.ggi-project.org/
COMMENT=	General Graphics Interface library is a flexible drawing library

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_BUILDLINK3=		yes
USE_PKGINSTALL=		yes
USE_X11=		yes
USE_LIBTOOL=		yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-debug
CONFIGURE_ARGS+=	--with-x
CONFIGURE_ARGS+=	--sysconfdir="${PKG_SYSCONFDIR}"

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

.if exists(${X11BASE}/include/X11/extensions/xf86dga.h)
#
# it would be more logical to set PLIST_SRC to PLIST first and then add
# PLIST.dga to it, but @dirrm lib/ggi/display will fail while processing
# pkg/PLIST, because the directory still contains files (they are listed in
# PLIST.dga) and isn't empty, thus can't be removed
#
PLIST_SRC=              ${PKGDIR}/PLIST.dga
PLIST_SRC+=             ${PKGDIR}/PLIST
.endif

.include "../../devel/ncurses/buildlink3.mk"
.include "../../graphics/libgii/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
