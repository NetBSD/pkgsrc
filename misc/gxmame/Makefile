# $NetBSD: Makefile,v 1.2 2004/01/03 18:49:46 reed Exp $
#

DISTNAME=	gxmame-0.34b
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gxmame/}

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://gxmame.sourceforge.net/
COMMENT=	Frontend for XMame using the GTK2 library

BUILD_USES_MSGFMT=	yes
DEPENDS=		gnome2-dirs>=1.2:../../misc/gnome2-dirs
DEPENDS+=		xmame-[0-9]*:../../emulators/xmame

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_GMAKE=		yes
USE_PKGLOCALEDIR=	yes
USE_X11=		yes

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
