# $NetBSD: Makefile,v 1.65 2012/10/02 17:11:11 tron Exp $
#

DISTNAME=	giram-0.3.5
PKGREVISION=	19
CATEGORIES=	graphics
MASTER_SITES=	http://www.giram.org/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.giram.org/
COMMENT=	Giram Is Really A Modeller

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	povray-[0-9]*:../../graphics/povray

USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake pkg-config msgfmt intltool
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES

PKG_SYSCONFSUBDIR=	giram

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}/0.3

SHLIBTOOL_OVERRIDE=	# empty

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
