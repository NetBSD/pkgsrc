# $NetBSD: Makefile,v 1.11 2004/04/01 18:29:19 jmmv Exp $
#

DISTNAME=		gnome-icon-theme-1.2.0
CATEGORIES=		graphics gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-icon-theme/1.2/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Theme consisting of a set of icons for GNOME

DEPENDS+=		hicolor-icon-theme>=0.4:../../graphics/hicolor-icon-theme

BUILD_USES_MSGFMT=	yes
DEPENDS+=		xdg-dirs>=1.1:../../misc/xdg-dirs

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_PERL5=		build
USE_PKGLOCALEDIR=	yes

PKGCONFIG_OVERRIDE=	gnome-icon-theme.pc.in

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
