# $NetBSD: Makefile,v 1.1.1.1 2002/10/16 08:58:43 rh Exp $
#

DISTNAME=	coconut-0.3.0
CATEGORIES=	devel
MASTER_SITES=	http://www.asahi-net.or.jp/~em7t-hmd/coconut/		\
		${MASTER_SITE_SOURCEFORGE:=coconut-lib/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://sourceforge.net/projects/coconut-lib/
COMMENT=	Objective-C library for Unix-like systems

USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
USE_NCURSES=	YES
USE_X11=	YES
GNU_CONFIGURE=	YES
CPPFLAGS+=	-I${PREFIX}/include/libxml2/libxml
LIBTOOL_OVERRIDE=${WRKSRC}/libtool

pre-configure:
	cd ${WRKSRC} &&							\
	${CP} configure configure.old &&				\
	${SED} < configure.old > configure				\
	's|^\(INCLUDE_DIR_LIST=\).*|\1"${PREFIX}/include ${X11PREFIX}/include"|'

.include "../../graphics/gtkglext/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../textproc/libxslt/buildlink2.mk"
.include "../../devel/ncurses/buildlink2.mk"
.include "../../devel/papaya/buildlink2.mk"
.include "../../devel/popt/buildlink2.mk"
.include "../../net/gnet/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
