# $NetBSD: Makefile,v 1.17 2000/11/02 01:56:14 itojun Exp $
#

DISTNAME=	xtraceroute-0.8.14
CATEGORIES=	net x11
MASTER_SITES=	http://www.dtek.chalmers.se/~d3august/xt/dl/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		ndg_files.tar.gz

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.dtek.chalmers.se/~d3august/xt/index.html

BUILD_DEPENDS+=	msgfmt:../../devel/gettext
DEPENDS+=	gtkglarea-1.2.1:../../x11/gtkglarea
DEPENDS+=	tiff-*:../../graphics/tiff

USE_X11=	yes
USE_MESA=	yes
GNU_CONFIGURE=	yes
USE_LIBINTL=	yes

EVAL_PREFIX+=	GTKDIR=gtk+
CONFIGURE_ARGS+= --with-gtk-prefix="${GTKDIR}"
# XXX Actually, Mesa's in X11PREFIX too, but as our tiff is in LOCALBASE
# and xtraceroute doesn't have a switch to tell it so (yet?), we abuse
# the --with-GL-prefix switch for this.
CONFIGURE_ARGS+= --with-GL-prefix=${LOCALBASE}
CONFIGURE_ARGS+= --with-lib-MesaGL

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/xtraceroute
	${INSTALL_DATA} ${WRKDIR}/hosts.cache    ${PREFIX}/share/xtraceroute/hosts.cache
	${INSTALL_DATA} ${WRKDIR}/networks.cache ${PREFIX}/share/xtraceroute/networks.cache

.include "../../mk/bsd.pkg.mk"
