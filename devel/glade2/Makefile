# $NetBSD: Makefile,v 1.34 2004/11/26 09:49:10 adam Exp $

DISTNAME=	glade-2.6.5
PKGNAME=	${DISTNAME:S/-/2-/}
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/glade/2.6/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	sab@posix.org.uk
HOMEPAGE=	http://glade.gnome.org/
COMMENT=	User interface builder for the GTK2+ toolkit and GNOME2

BUILD_USES_MSGFMT=	YES

USE_BUILDLINK3=		YES
USE_DIRS+=		gnome2-1.5
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
USE_X11=		YES
GNU_CONFIGURE=		YES

.include "../../databases/libgda/buildlink3.mk"
.include "../../databases/libgnomedb/buildlink3.mk"
.include "../../devel/gail/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../print/libgnomeprintui/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
