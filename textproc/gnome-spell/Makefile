# $NetBSD: Makefile,v 1.3 2004/02/15 18:39:22 jmmv Exp $

DISTNAME=	gnome-spell-1.0.5
PKGREVISION=	1
CATEGORIES=	textproc gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-spell/1.0/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Spell checking as you type like gtkspell

DEPENDS=		gnome2-dirs>=1.3:../../misc/gnome2-dirs

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_PKGLOCALEDIR=	YES
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		YES

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
