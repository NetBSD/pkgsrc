# $NetBSD: Makefile,v 1.32 2001/02/17 17:42:22 wiz Exp $
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
BUILD_DEPENDS+=	${LOCALBASE}/egcs/bin/g++:../../lang/egcs
CONFIGURE_ENV+=	CXX=${LOCALBASE}/egcs/bin/g++
CONFIGURE_ENV+= CPPFLAGS="${CPPFLAGS} -I${X11BASE}/include"
CONFIGURE_ENV+= LIBS="${LIBS} -lsocket -lnsl"
USE_GMAKE=	YES
.endif

.include "../../mk/bsd.pkg.mk"
