# $NetBSD: Makefile,v 1.35 2001/06/12 20:33:08 jlam Exp $
#

DISTNAME=       xosview-1.7.0.b
PKGNAME=	xosview-1.7.0b
CATEGORIES=	sysutils
MASTER_SITES=   http://www.ece.utexas.edu/~bgrayson/xosview/ \
		http://lore.ece.utexas.edu/~bgrayson/xosview/

MAINTAINER=	bgrayson@netbsd.org
HOMEPAGE=	http://lore.ece.utexas.edu/~bgrayson/xosview.html
COMMENT=	X11 graphical display of OS statistics

HAS_CONFIGURE=	YES
CONFIGURE_ARGS+= --prefix=${PREFIX}
USE_X11BASE=	YES
USE_XPM=	YES

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
BUILD_DEFS=	UVM
.elif ${OPSYS} == "SunOS"
BUILD_DEPENDS+=	egcs-1.1.2:../../lang/egcs
CONFIGURE_ENV+=	CXX=${LOCALBASE}/egcs/bin/g++
CPPFLAGS+=	-I${X11BASE}/include
LIBS+=		-lsocket -lnsl
USE_GMAKE=	YES
.endif

.include "../../mk/bsd.pkg.mk"
