# $NetBSD: Makefile,v 1.4 2002/09/21 08:33:48 jlam Exp $
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

USE_BUILDLINK2=		YES
USE_X11=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=        --localstatedir=${LOCALSTATEDIR}

LOCALSTATEDIR=          ${X11PREFIX}/var/gnome

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../sysutils/gnome-vfs/buildlink2.mk"
.include "../../textproc/libxml/buildlink2.mk"
.include "../../textproc/scrollkeeper/buildlink2.mk"
.include "../../x11/gnome-libs/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
