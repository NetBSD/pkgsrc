# $NetBSD: Makefile,v 1.36 2001/09/23 06:00:27 jlam Exp $
#

DISTNAME=       xosview-1.7.0.b
PKGNAME=	xosview-1.7.0b
CATEGORIES=	sysutils
MASTER_SITES=   http://www.ece.utexas.edu/~bgrayson/xosview/ \
		http://lore.ece.utexas.edu/~bgrayson/xosview/

MAINTAINER=	bgrayson@netbsd.org
HOMEPAGE=	http://lore.ece.utexas.edu/~bgrayson/xosview.html
COMMENT=	X11 graphical display of OS statistics

HAS_CONFIGURE=		YES
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--x-includes=${BUILDLINK_X11_DIR}/include
CONFIGURE_ARGS+=	--x-libraries=${BUILDLINK_X11_DIR}/lib

USE_X11BASE=		YES
USE_BUILDLINK_ONLY=	YES

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
BUILD_DEFS=	UVM
.elif ${OPSYS} == "SunOS"
BUILD_DEPENDS+=	egcs-1.1.2:../../lang/egcs
CONFIGURE_ENV+=	CXX=${LOCALBASE}/egcs/bin/g++
CPPFLAGS+=	-I${BUILDLINK_X11_DIR}/include
LIBS+=		-lsocket -lnsl
USE_GMAKE=	YES
.endif

.include "../../graphics/xpm/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
