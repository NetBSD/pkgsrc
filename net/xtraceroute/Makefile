# $NetBSD: Makefile,v 1.33 2003/11/30 22:58:40 jschauma Exp $
#

DISTNAME=	xtraceroute-0.8.14
PKGREVISION=	4
CATEGORIES=	net x11
MASTER_SITES=	http://www.dtek.chalmers.se/~d3august/xt/dl/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		ndg_files.tar.gz

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://www.dtek.chalmers.se/~d3august/xt/index.html
COMMENT=	Graphical version of traceroute, which traces the route IP packets go

BUILD_USES_MSGFMT=	yes

USE_X11=		yes
GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes

CONFIGURE_ARGS+= --with-gtk-prefix="${BUILDLINK_PREFIX.gtk}"
# XXX Actually, Mesa's in X11PREFIX too, but as our tiff is in LOCALBASE
# and xtraceroute doesn't have a switch to tell it so (yet?), we abuse
# the --with-GL-prefix switch for this.
CONFIGURE_ARGS+= --with-GL-prefix=${LOCALBASE}
CONFIGURE_ARGS+= --with-lib-MesaGL

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/xtraceroute
	${INSTALL_DATA} ${WRKDIR}/hosts.cache    ${PREFIX}/share/xtraceroute/hosts.cache
	${INSTALL_DATA} ${WRKDIR}/networks.cache ${PREFIX}/share/xtraceroute/networks.cache

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"
.include "../../graphics/MesaLib/buildlink2.mk"
.include "../../graphics/glu/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../x11/gtkglarea/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
