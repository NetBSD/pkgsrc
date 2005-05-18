# $NetBSD: Makefile,v 1.24 2005/05/18 16:22:15 jmmv Exp $
#

DISTNAME=		gnome-icon-theme-2.10.1
CATEGORIES=		graphics gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-icon-theme/2.10/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Theme consisting of a set of icons for GNOME

BUILD_USES_MSGFMT=	yes

GNU_CONFIGURE=		yes
USE_DIRS+=		xdg-1.1
USE_GNU_TOOLS+=		make
USE_PERL5=		build
USE_PKGLOCALEDIR=	yes

PKGCONFIG_OVERRIDE=	gnome-icon-theme.pc.in

BUILDLINK_DEPENDS.hicolor-icon-theme=	hicolor-icon-theme>=0.5

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
