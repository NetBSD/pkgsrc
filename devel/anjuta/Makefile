# $NetBSD: Makefile,v 1.7 2002/11/30 23:21:33 salo Exp $
#

DISTNAME=		anjuta-0.1.9
PKGREVISION=		2
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=anjuta/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://anjuta.sourceforge.net
COMMENT=		Gnome based IDE for C and C++

DEPENDS+=               pkgconfig>=0.8.0:../../devel/pkgconfig
DEPENDS+=		xml-i18n-tools>=0.9:../../textproc/xml-i18n-tools

BUILD_USES_MSGFMT=	YES

USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_X11=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=        --localstatedir=${LOCALSTATEDIR}

LOCALSTATEDIR=          ${X11PREFIX}/var

.include "../../devel/bonobo/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../sysutils/gnome-vfs/buildlink2.mk"
.include "../../textproc/libxml/buildlink2.mk"
.include "../../textproc/scrollkeeper/buildlink2.mk"
.include "../../x11/gnome-libs/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
