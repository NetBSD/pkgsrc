# $NetBSD: Makefile,v 1.16 2002/11/25 20:48:42 jlam Exp $
#

DISTNAME=	libggi-2.0b2.1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.ggi-project.org/pub/ggi/ggi/current/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.ggi-project.org/
COMMENT=	General Graphics Interface library is a flexible drawing library

USE_BUILDLINK2=		# defined
USE_X11=		# defined
USE_NCURSES=		not sure if this is really needed??

USE_LIBTOOL=		# defined
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--disable-debug
CONFIGURE_ARGS+=	--with-x

PLIST_SRC=	${WRKDIR}/PLIST

post-configure:
	@if [ -f ${X11BASE}/include/X11/extensions/xf86dga.h ]; then	\
		${CP} ${PKGDIR}/PLIST ${PLIST_SRC};			\
	else								\
		${GREP} -v lib.ggi.display.xf86dga ${PKGDIR}/PLIST	\
			> ${PLIST_SRC};					\
	fi

.include "../../devel/ncurses/buildlink2.mk"
.include "../../graphics/libgii/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
