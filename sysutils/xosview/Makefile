# $NetBSD: Makefile,v 1.26 1999/04/07 10:09:18 agc Exp $
#

DISTNAME=       xosview-1.7.0.b
CATEGORIES=	sysutils
MASTER_SITES=   http://www.ece.utexas.edu/~bgrayson/xosview/ \
		http://lore.ece.utexas.edu/~bgrayson/xosview/

MAINTAINER=	bgrayson@ece.utexas.edu
HOMEPAGE=	http://lore.ece.utexas.edu/~bgrayson/xosview.html

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+= --prefix=${PREFIX}
USE_X11BASE=	yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
BUILD_DEFS=	UVM

# On arm32, with UVM, pmap.h contains a C++ keyword. Workaround this.
pre-build:
	@if [ ${MACHINE} = "arm32" -a ! -z "${UVM}" ]; then		\
		${MKDIR} ${WRKSRC}/include/machine;			\
		${SED} -e 's|virtual|virt|' /usr/include/machine/pmap.h \
			> ${WRKSRC}/include/machine/pmap.h; 		\
	fi

.elif ${OPSYS} == "SunOS"
DEPENDS+=	egcs-1.1.2:../../lang/egcs
CONFIGURE_ENV+=	CXX=${LOCALBASE}/egcs/bin/g++
USE_GMAKE=	yes
.endif

.include "../../mk/bsd.pkg.mk"
