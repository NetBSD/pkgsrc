# $NetBSD: Makefile,v 1.16 2003/11/12 01:31:47 salo Exp $
#

DISTNAME=		anjuta-1.0.1
PKGREVISION=		5
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=anjuta/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.anjuta.org/
COMMENT=		Gnome based IDE for C and C++

BUILD_USES_MSGFMT=	YES
DEPENDS+=		gnome1-dirs>=1.2:../../misc/gnome1-dirs

USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_X11=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=        --localstatedir=${LOCALSTATEDIR}

LOCALSTATEDIR=          ${X11PREFIX}/var

.include "../../devel/bonobo/buildlink2.mk"
.include "../../devel/libglade/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../sysutils/gnome-vfs/buildlink2.mk"
.include "../../textproc/libxml/buildlink2.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../textproc/xml-i18n-tools/buildlink2.mk"
.include "../../x11/gnome-libs/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
