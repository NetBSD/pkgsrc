# $NetBSD: Makefile,v 1.11 2011/07/27 11:14:22 cherry Exp $
#

DISTNAME=	ski-1.3.2
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ski/}

MAINTAINER=	cherry@zyx.in
HOMEPAGE=	http://ski.sourceforge.net/
COMMENT=	The ia64 instruction set simulator

PKG_DESTDIR_SUPPORT=        user-destdir

BUILD_DEPENDS+= libelf>=0.8.13:../../devel/libelf
GNU_CONFIGURE=	yes
USE_LANGUAGES+= c fortran77 c++
CONFIGURE_ARGS+= --prefix=${PREFIX}

CPPFLAGS+=	-I${PREFIX}/include/libelf -L ${PREFIX}/lib

USE_TOOLS+=	pkg-config aclocal autoconf automake
USE_LIBTOOL=	yes
USE_NCURSES=	yes


pre-configure:
#	cd  ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${SH} ./autogen.sh ${CONFIGURE_ARGS}
	cd ${WRKSRC} && ${SH} ./autogen.sh ${CONFIGURE_ARGS}

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/lib/X11/app-defaults
	${INSTALL_DATA} ${WRKSRC}/src/XSki \
			${DESTDIR}${PREFIX}/lib/X11/app-defaults/XSki

.include "../../devel/gperf/buildlink3.mk"
.include "../../devel/libelf/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
