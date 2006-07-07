# $NetBSD: Makefile,v 1.22 2006/07/07 22:03:50 jlam Exp $
#

DISTNAME=	gxmame-0.35beta1
PKGREVISION=	4
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gxmame/}

MAINTAINER=	flynn@energyhq.es.eu.org
HOMEPAGE=	http://gxmame.sourceforge.net/
COMMENT=	Frontend for XMame using the GTK2 library

DEPENDS+=		xmame>=0.87:../../emulators/xmame

GNU_CONFIGURE=		yes
USE_DIRS+=		gnome2-1.5
USE_TOOLS+=		intltool gmake msgfmt pkg-config
USE_PKGLOCALEDIR=	yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
