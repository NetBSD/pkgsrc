# $NetBSD: Makefile,v 1.55 2008/04/30 13:38:14 jmmv Exp $
#

DISTNAME=	gail-1.22.1
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gail/1.22/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://developer.gnome.org/projects/gap/
COMMENT=	GNOME Accessibility Implementation Library

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config msgfmt
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes

PKGCONFIG_OVERRIDE=	gail.pc.in
PKGCONFIG_OVERRIDE+=	gail-uninstalled.pc.in

BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.10.0
BUILDLINK_API_DEPENDS.atk=	atk>=1.13.0

.include "../../devel/atk/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
