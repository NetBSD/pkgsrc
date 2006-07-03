# $NetBSD: Makefile,v 1.1.1.1 2006/07/03 23:31:04 wiz Exp $
#

DISTNAME=		libvisual-plugins-0.2.0
PKGNAME=		libvisual0.2-plugins-0.2.0
CATEGORIES=		audio graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=libvisual/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://libvisual.sourceforge.net/
COMMENT=		Plugins for libvisual

CONFLICTS=		libvisual-nebulus-[0-9]* libvisual-gforce-[0-9]*
CONFLICTS+=		libvisual-plugins<0.4.0

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config mkdirhier

# sigsegfaults in 0.2.0 because of:
# sorry, but the bug with strtof has come, please report..
CONFIGURE_ARGS+=	--disable-dancingparticles

# install unnecessarily installed files
post-install:
	${RM} ${PREFIX}/share/libvisual-plugins/*/Makefile*

.include "../../audio/goom/buildlink3.mk"
.include "../../audio/libvisual0.2/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
# currently not useful, since libgdkpixbuf plugin is not configurable
#.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
