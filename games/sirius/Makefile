# $NetBSD: Makefile,v 1.8 2003/12/13 00:45:23 wiz Exp $
#

DISTNAME=	sirius-0.7.0
PKGREVISION=	3
CATEGORIES=	games gnome
MASTER_SITES=	http://sirius.bitvis.nu/files/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://sirius.bitvis.nu/
COMMENT=	Othello game for GNOME2

BUILD_USES_MSGFMT=	YES
DEPENDS=		gnome2-dirs>=1.1:../../misc/gnome2-dirs

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
USE_X11=		YES

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../devel/GConf2/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../graphics/libgnomecanvas/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
