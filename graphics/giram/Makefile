# $NetBSD: Makefile,v 1.25 2003/03/09 19:17:56 jschauma Exp $

DISTNAME=	giram-0.3.4
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.giram.org/downloads/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.giram.org/
COMMENT=	Giram Is Really A Modeller

DEPENDS+=	povray-[0-9]*:../../graphics/povray

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_PKGINSTALL=		yes
USE_X11=		yes
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
BUILD_DEPENDS+=		bison:../../devel/bison

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

PKG_SYSCONFSUBDIR=	giram

CONF_FILES+=	${PREFIX}/share/examples/giram/giramrc		\
		${PKG_SYSCONFDIR}/giramrc
CONF_FILES+=	${PREFIX}/share/examples/giram/giramrc_user	\
		${PKG_SYSCONFDIR}/giramrc_user
CONF_FILES+=	${PREFIX}/share/examples/giram/gtkrc		\
		${PKG_SYSCONFDIR}/gtkrc
CONF_FILES+=	${PREFIX}/share/examples/giram/gtkrc_user	\
		${PKG_SYSCONFDIR}/gtkrc_user
CONF_FILES+=	${PREFIX}/share/examples/giram/ps-menurc	\
		${PKG_SYSCONFDIR}/ps-menurc

.include "../../graphics/MesaLib/buildlink2.mk"
.include "../../graphics/glu/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
