# $NetBSD: Makefile,v 1.19 2004/03/08 19:40:36 jmmv Exp $

DISTNAME=	gnomeicu-0.96
PKGREVISION=	10
CATEGORIES=	chat gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gnomeicu/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://gnomeicu.sourceforge.net/
COMMENT=	GNOME ICQ client

DEPENDS+=	xdg-x11-dirs>=1.1:../../misc/xdg-x11-dirs

USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
USE_X11BASE=		YES
USE_GNU_TOOLS+=		make

.include "../../databases/gdbm/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../x11/gnome-core/buildlink2.mk"
.include "../../converters/libiconv/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
