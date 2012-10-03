# $NetBSD: Makefile,v 1.19.2.1 2012/10/03 12:09:31 spz Exp $
#

DISTNAME=	pcmanfm-0.1.8.9
PKGREVISION=	15
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pcmanfm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pcmanfm.sourceforge.net/
COMMENT=	Extremly fast and lightweight file manager

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config msgfmt

DEPENDS+=	gamin>=0.1.10:../../sysutils/gamin

.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../sysutils/libgamin/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
