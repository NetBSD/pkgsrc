# $NetBSD: Makefile,v 1.19 1998/11/04 16:58:09 agc Exp $
#

DISTNAME=       xosview-1.6.2.a
CATEGORIES=	sysutils
MASTER_SITES=   http://www.ece.utexas.edu/~bgrayson/xosview/ \
		http://lore.ece.utexas.edu/~bgrayson/xosview/

MAINTAINER=	bgrayson@ece.utexas.edu
HOMEPAGE=	http://lore.ece.utexas.edu/~bgrayson/xosview.html

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+= --prefix=${PREFIX}
USE_X11=	yes
BUILD_DEFS=	UVM

# On arm32, with UVM, pmap.h contains a C++ keyword. Workaround this.
pre-build:
	mach=`/usr/bin/uname -m`;				\
	if [ $$mach = "arm32" -a ! -z "${UVM}" ]; then		\
		${MKDIR} -p ${WRKSRC}/include/machine;		\
		${SED} -e 's|virtual|virt|' /usr/include/machine/pmap.h \
			> ${WRKSRC}/include/machine/pmap.h; 	\
	fi

.include "../../mk/bsd.pkg.mk"
