# $NetBSD: Makefile,v 1.18 1998/11/04 16:37:11 agc Exp $
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

pre-build:
	mach=`/usr/bin/uname -m`;					\
	if [ ! -z "${UVM}" -a -e ${FILESDIR}/$$mach-pmap.h ]; then	\
		${MKDIR} -p ${WRKSRC}/include/machine;			\
		${CP} ${FILESDIR}/$$mach-pmap.h ${WRKSRC}/include/machine/pmap.h; \
	fi

BUILD_DEFS=	UVM

.include "../../mk/bsd.pkg.mk"
