# $NetBSD: Makefile,v 1.77 2020/06/02 08:23:34 adam Exp $
#

DISTNAME=	coconut-0.3.0
PKGREVISION=	52
CATEGORIES=	devel
MASTER_SITES=	# ${MASTER_SITE_SOURCEFORGE:=coconut-lib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/coconut-lib/
COMMENT=	Objective-C library for Unix-like systems

BUILD_DEPENDS+=	papaya>=0.1.7:../../devel/papaya

USE_TOOLS+=	pkg-config
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
CPPFLAGS+=	-I${PREFIX}/include/libxml2/libxml -DGL_GLEXT_LEGACY
MAKE_ENV+=	AM_MAKEFLAGS="am__depfiles_maybe="

SUBST_CLASSES+=			g_memmove
SUBST_MESSAGE.g_memmove=	Eliminating g_memmove.
SUBST_STAGE.g_memmove=		pre-configure
SUBST_FILES.g_memmove=		coconut/cmemalloc.m coconut/cstack.m \
				coconut/cset.m
SUBST_SED.g_memmove=		-e s,g_memmove,memmove,g

.include "../../graphics/gtkglext/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../net/gnet1/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

pre-configure:
	cd ${WRKSRC} &&							\
	${CP} configure configure.old &&				\
	${SED} < configure.old > configure				\
	's|^\(INCLUDE_DIR_LIST=\).*|\1"${PREFIX}/include ${X11BASE}/include"|'

.include "../../mk/bsd.pkg.mk"
