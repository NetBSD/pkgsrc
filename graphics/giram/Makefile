# $NetBSD: Makefile,v 1.39 2004/10/03 00:14:51 tv Exp $
#

DISTNAME=	giram-0.3.5
PKGREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	http://www.giram.org/downloads/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.giram.org/
COMMENT=	Giram Is Really A Modeller

DEPENDS+=	povray-[0-9]*:../../graphics/povray
BUILD_DEPENDS+=	bison-[0-9]*:../../devel/bison

USE_BUILDLINK3=		YES
USE_PKGLOCALEDIR=	YES
USE_PKGINSTALL=		YES
USE_X11=		YES
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES

PKG_SYSCONFSUBDIR=	giram

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}/0.3

SHLIBTOOL_OVERRIDE=	libtool

BUILDLINK_TRANSFORM+=	rm:-DGTK_DISABLE_DEPRECATED

OWN_DIRS+=	${PKG_SYSCONFDIR}/0.3
CONF_FILES+=	${PREFIX}/share/examples/giram/giramrc		\
		${PKG_SYSCONFDIR}/0.3/giramrc
CONF_FILES+=	${PREFIX}/share/examples/giram/giramrc_user	\
		${PKG_SYSCONFDIR}/0.3/giramrc_user
CONF_FILES+=	${PREFIX}/share/examples/giram/gtkrc		\
		${PKG_SYSCONFDIR}/0.3/gtkrc
CONF_FILES+=	${PREFIX}/share/examples/giram/gtkrc_user	\
		${PKG_SYSCONFDIR}/0.3/gtkrc_user
CONF_FILES+=	${PREFIX}/share/examples/giram/ps-menurc	\
		${PKG_SYSCONFDIR}/0.3/ps-menurc

.include "../../graphics/lib3ds/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
