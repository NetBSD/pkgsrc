# $NetBSD: Makefile,v 1.7 1999/07/22 23:45:28 sakamoto Exp $
#

DISTNAME=	xtraceroute-0.8.14
CATEGORIES=	net x11
MASTER_SITES=	http://www.dtek.chalmers.se/~d3august/xt/dl/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		ndg_files.tar.gz

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.dtek.chalmers.se/~d3august/xt/index.html

DEPENDS+=	Mesa-3.0:../../graphics/Mesa
DEPENDS+=	gtkglarea-1.2.1:../../x11/gtkglarea
DEPENDS+=	tiff-3.4:../../graphics/tiff

USE_X11=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --with-gtk-prefix=${X11BASE}
# XXX Actually, Mesa's in X11BASE too, but as our tiff is in LOCALBASE
# and xtraceroute doesn't have a switch to tell it so (yet?), we abuse
# the --with-GL-prefix switch for this.
CONFIGURE_ARGS+= --with-GL-prefix=${LOCALBASE}
CONFIGURE_ARGS+= --with-lib-MesaGL

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/xtraceroute
	${INSTALL_DATA} ${WRKDIR}/hosts.cache    ${PREFIX}/share/xtraceroute/hosts.cache
	${INSTALL_DATA} ${WRKDIR}/networks.cache ${PREFIX}/share/xtraceroute/networks.cache

.include "../../mk/bsd.pkg.mk"
