# $NetBSD: Makefile,v 1.29 2009/08/26 19:57:43 sno Exp $

DISTNAME=	gqview-2.1.5
PKGREVISION=	2
CATEGORIES=	graphics x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gqview/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://gqview.sourceforge.net/
COMMENT=	GTK2-based graphic file viewer (development version)

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		msgfmt pkg-config
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
