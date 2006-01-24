# $NetBSD: Makefile,v 1.15 2006/01/24 07:32:36 wiz Exp $

DISTNAME=	gnome-spell-1.0.6
PKGREVISION=	2
CATEGORIES=	textproc gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-spell/1.0/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Spell checking as you type like gtkspell

GNU_CONFIGURE=		YES
USE_DIRS+=		gnome2-1.3
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake pkg-config
USE_LIBTOOL=		YES

BUILDLINK_DEPENDS.libgnomeui+=	libgnomeui>=2.8.0nb3

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../textproc/aspell/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
