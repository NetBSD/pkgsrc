# $NetBSD: Makefile,v 1.29 2000/07/13 15:48:47 agc Exp $
#

DISTNAME=       xosview-1.7.0.b
CATEGORIES=	sysutils
MASTER_SITES=   http://www.ece.utexas.edu/~bgrayson/xosview/ \
		http://lore.ece.utexas.edu/~bgrayson/xosview/

MAINTAINER=	bgrayson@netbsd.org
HOMEPAGE=	http://lore.ece.utexas.edu/~bgrayson/xosview.html

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+= --prefix=${PREFIX}
USE_X11BASE=	yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
BUILD_DEFS=	UVM
.elif ${OPSYS} == "SunOS"
DEPENDS+=	xpm-*:../../graphics/xpm
BUILD_DEPENDS+=	${LOCALBASE}/egcs/bin/g++:../../lang/egcs
CONFIGURE_ENV+=	CXX=${LOCALBASE}/egcs/bin/g++
CONFIGURE_ENV+= CPPFLAGS="${CPPFLAGS} -I${X11BASE}/include"
CONFIGURE_ENV+= LIBS="${LIBS} -lsocket -lnsl"
USE_GMAKE=	yes
.endif

.include "../../mk/bsd.pkg.mk"
