# $NetBSD: Makefile,v 1.27 2003/05/24 11:23:08 salo Exp $
#

DISTNAME=	giram-0.3.5
CATEGORIES=	graphics
MASTER_SITES=	http://www.giram.org/downloads/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.giram.org/
COMMENT=	Giram Is Really A Modeller

DEPENDS+=	povray-[0-9]*:../../graphics/povray
BUILD_DEPENDS+=	bison:../../devel/bison

USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_PKGINSTALL=		YES
USE_X11=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES

PKG_SYSCONFSUBDIR=	giram

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}/0.3

SHLIBTOOL_OVERRIDE=	${WRKSRC}/libtool

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

.include "../../graphics/lib3ds/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
