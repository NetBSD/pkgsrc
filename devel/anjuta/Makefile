# $NetBSD: Makefile,v 1.3 2002/07/16 12:17:12 agc Exp $
#

DISTNAME=		anjuta-0.1.9
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=anjuta/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://anjuta.sourceforge.net
COMMENT=		Gnome based IDE for C and C++

DEPENDS+=               pkgconfig>=0.8.0:../../devel/pkgconfig
DEPENDS+=		xml-i18n-tools>=0.9:../../textproc/xml-i18n-tools

BUILD_USES_MSGFMT=	YES
GNU_CONFIGURE=		YES
USE_X11=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES

CONFIGURE_ARGS+=        --localstatedir=${LOCALSTATEDIR}
LOCALSTATEDIR=          ${X11PREFIX}/var/gnome

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../sysutils/gnome-vfs/buildlink.mk"
.include "../../textproc/libxml/buildlink.mk"
.include "../../textproc/scrollkeeper/buildlink.mk"
.include "../../x11/gnome-libs/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
