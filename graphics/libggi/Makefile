# $NetBSD: Makefile,v 1.14 2002/01/11 11:47:54 skrll Exp $
#

DISTNAME=	libggi-2.0b2.1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.ggi-project.org/pub/ggi/ggi/current/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.ggi-project.org/
COMMENT=	General Graphics Interface library is a flexible drawing library

BUILD_DEPENDS+=	autoconf>=2.13:../../devel/autoconf
DEPENDS+=	ncurses>=4.2:../../devel/ncurses
DEPENDS+=	libgii-0.6:../libgii

USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	\
	--disable-debug \
	--with-x \
	--with-extra-includes=${LOCALBASE}/include \
	--with-extra-libs="${X11BASE}/lib -Wl,-R${X11BASE}/lib"

PLIST_SRC=	${WRKDIR}/PLIST

post-configure:
	@if [ -f ${X11BASE}/include/X11/extensions/xf86dga.h ]; then \
		${CP} ${PKGDIR}/PLIST ${PLIST_SRC}; \
	else \
		${GREP} -v lib.ggi.display.xf86dga ${PKGDIR}/PLIST \
			> ${PLIST_SRC}; \
	fi

post-install:
	cd ${PREFIX}/man/man3 ; for i in *.3ggi ; do \
		${MV} $$i `basename $$i .3ggi`.3 ; \
	done
	cd ${PREFIX}/man/man7 ; for i in *.7ggi ; do \
		${MV} $$i `basename $$i .7ggi`.7 ; \
	done

.include "../../mk/bsd.pkg.mk"
