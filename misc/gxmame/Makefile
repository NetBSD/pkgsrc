# $NetBSD: Makefile,v 1.9 2004/11/07 21:13:23 kristerw Exp $
#

DISTNAME=	gxmame-0.34b
PKGREVISION=	4
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gxmame/}

MAINTAINER=	flynn@energyhq.es.eu.org
HOMEPAGE=	http://gxmame.sourceforge.net/
COMMENT=	Frontend for XMame using the GTK2 library

BUILD_USES_MSGFMT=	yes
DEPENDS+=		xmame>=0.87:../../emulators/xmame

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_DIRS+=		gnome2-1.5
USE_GNU_TOOLS+=		make
USE_PKGLOCALEDIR=	yes
USE_X11=		yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
