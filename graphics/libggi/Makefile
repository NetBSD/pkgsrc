# $NetBSD: Makefile,v 1.23 2003/09/27 17:07:36 grant Exp $
#

DISTNAME=	libggi-2.0.3.src
PKGNAME=	${DISTNAME:S/.src//}
PKGREVISION=			1
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.ggi-project.org/pub/ggi/ggi/v2.0/ \
		http://www.ggi-project.org/ftp/ggi/v2.0/ \
		${MASTER_SITE_SOURCEFORGE:=ggi/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://www.ggi-project.org/
COMMENT=	General Graphics Interface library is a flexible drawing library

USE_BUILDLINK2=		yes
USE_PKGINSTALL=		yes
USE_X11=		yes

USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-debug
CONFIGURE_ARGS+=	--with-x
CONFIGURE_ARGS+=	--sysconfdir="${PKG_SYSCONFDIR}"

PKG_SYSCONFSUBDIR=	ggi
EGDIR=			${PREFIX}/share/examples/ggi
CONF_FILES=		${EGDIR}/libggi.conf ${PKG_SYSCONFDIR}/libggi.conf

.include "../../mk/bsd.prefs.mk"

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

.include "../../mk/curses.buildlink2.mk"
.include "../../graphics/libgii/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
