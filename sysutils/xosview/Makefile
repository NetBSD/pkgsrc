# $NetBSD: Makefile,v 1.22 1999/01/30 23:18:54 agc Exp $
#

DISTNAME=       xosview-1.6.2.a
CATEGORIES=	sysutils
MASTER_SITES=   http://www.ece.utexas.edu/~bgrayson/xosview/ \
		http://lore.ece.utexas.edu/~bgrayson/xosview/

MAINTAINER=	bgrayson@ece.utexas.edu
HOMEPAGE=	http://lore.ece.utexas.edu/~bgrayson/xosview.html

CONFLICTS=	xosview-*

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+= --prefix=${PREFIX}
USE_X11BASE=	yes
BUILD_DEFS=	UVM

# On arm32, with UVM, pmap.h contains a C++ keyword. Workaround this.
pre-build:
	@if [ ${MACHINE} = "arm32" -a ! -z "${UVM}" ]; then		\
		${MKDIR} ${WRKSRC}/include/machine;			\
		${SED} -e 's|virtual|virt|' /usr/include/machine/pmap.h \
			> ${WRKSRC}/include/machine/pmap.h; 		\
	fi

.include "../../mk/bsd.pkg.mk"
