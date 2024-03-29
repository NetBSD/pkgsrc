# $NetBSD: Makefile,v 1.63 2023/10/21 17:11:15 gdt Exp $
#

DISTNAME=	xtraceroute-0.8.14
PKGREVISION=	16
CATEGORIES=	net x11
MASTER_SITES=	http://www.dtek.chalmers.se/~d3august/xt/dl/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		ndg_files.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.dtek.chalmers.se/~d3august/xt/index.html
COMMENT=	Graphical version of traceroute, which traces the route IP packets go

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt
USE_FEATURES=		snprintf

CONFIGURE_ARGS+=	--with-gtk-prefix="${BUILDLINK_PREFIX.gtk}"
CONFIGURE_ARGS+=	--with-GL-prefix=${LOCALBASE}
CONFIGURE_ARGS+=	--with-lib-MesaGL

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MIRIX-5*)
CONFIGURE_ARGS+=	--with-traceroute=/usr/etc/traceroute
.endif

INSTALLATION_DIRS+=	share/xtraceroute

post-install:
	${INSTALL_DATA} ${WRKDIR}/hosts.cache    ${DESTDIR}${PREFIX}/share/xtraceroute/hosts.cache
	${INSTALL_DATA} ${WRKDIR}/networks.cache ${DESTDIR}${PREFIX}/share/xtraceroute/networks.cache

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../x11/gtkglarea/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
