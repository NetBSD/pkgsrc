# $NetBSD: Makefile,v 1.29 2011/01/13 13:38:46 wiz Exp $
#

DISTNAME=	gxmame-0.35beta1
PKGREVISION=	9
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gxmame/}

MAINTAINER=	flynn@energyhq.es.eu.org
HOMEPAGE=	http://gxmame.sourceforge.net/
COMMENT=	Frontend for XMame using the GTK2 library

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		xmame>=0.87:../../emulators/xmame

GNU_CONFIGURE=		yes
USE_TOOLS+=		intltool gmake msgfmt pkg-config
USE_PKGLOCALEDIR=	yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
