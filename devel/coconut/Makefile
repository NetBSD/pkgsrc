# $NetBSD: Makefile,v 1.49 2012/10/02 17:10:45 tron Exp $
#

DISTNAME=	coconut-0.3.0
PKGREVISION=	29
CATEGORIES=	devel
MASTER_SITES=	# ${MASTER_SITE_SOURCEFORGE:=coconut-lib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/coconut-lib/
COMMENT=	Objective-C library for Unix-like systems

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+=	papaya>=0.1.7:../../devel/papaya

USE_TOOLS+=	pkg-config
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
CPPFLAGS+=	-I${PREFIX}/include/libxml2/libxml -DGL_GLEXT_LEGACY
MAKE_ENV+=	AM_MAKEFLAGS="am__depfiles_maybe="

.include "../../graphics/gtkglext/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../net/gnet1/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

pre-configure:
	cd ${WRKSRC} &&							\
	${CP} configure configure.old &&				\
	${SED} < configure.old > configure				\
	's|^\(INCLUDE_DIR_LIST=\).*|\1"${PREFIX}/include ${X11PREFIX}/include"|'

.include "../../mk/bsd.pkg.mk"
