# $NetBSD: Makefile,v 1.3 2003/12/13 00:45:22 wiz Exp $
#

DISTNAME=	gtranslator-1.0
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://www.gtranslator.org/download/releases/1.0/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.gtranslator.org/
COMMENT=	Gettext po file editor for the GNOME2 desktop environment

BUILD_USES_MSGFMT=	yes
DEPENDS=		gnome2-dirs>=1.2:../../misc/gnome2-dirs

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_GMAKE=		yes
USE_PKGLOCALEDIR=	yes
USE_X11=		yes
MANCOMPRESSED=		yes

CONFIGURE_ARGS+=	--disable-debug

.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../sysutils/gnome-vfs2/buildlink2.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtk2/buildlink2.mk"

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
