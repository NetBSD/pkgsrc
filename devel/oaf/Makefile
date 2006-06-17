# $NetBSD: Makefile,v 1.47 2006/06/17 17:29:12 rillig Exp $
#

DISTNAME=		oaf-0.6.10
PKGREVISION=		9
CATEGORIES=		devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/oaf/0.6/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		New object activation framework for GNOME

USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
USE_X11BASE=		YES
USE_TOOLS+=		bison lex msgfmt
USE_LIBTOOL=		YES

BROKEN_GETTEXT_DETECTION=	YES

CONFIGURE_ARGS+=	--enable-gtk-doc=no

EGDIR=			${PREFIX}/share/examples/oaf
INSTALL_MAKE_FLAGS+=	oafconfigdir=${EGDIR}
PKG_SYSCONFSUBDIR=	oaf
CONF_FILES+=		${EGDIR}/oaf-config.xml ${PKG_SYSCONFDIR}/oaf-config.xml

.include "../../devel/popt/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/libxml/buildlink3.mk"
.include "../../x11/gnome-libs/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
