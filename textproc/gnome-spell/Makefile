# $NetBSD: Makefile,v 1.8 2005/01/08 20:13:44 jmmv Exp $

DISTNAME=	gnome-spell-1.0.5
PKGREVISION=	5
CATEGORIES=	textproc gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-spell/1.0/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Spell checking as you type like gtkspell

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_DIRS+=		gnome2-1.3
USE_PKGLOCALEDIR=	YES
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		YES

BUILDLINK_DEPENDS.libgnomeui+=	libgnomeui>=2.8.0nb3

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../textproc/aspell/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
