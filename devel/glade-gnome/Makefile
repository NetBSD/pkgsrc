# $NetBSD: Makefile,v 1.10 2008/01/18 05:14:33 tnn Exp $

.include "../../devel/glade/Makefile.common"

PKGNAME=	${DISTNAME:S/glade/glade-gnome/}
PKGREVISION=	1
CATEGORIES+=	gnome

COMMENT+=	and GNOME2

CONFLICTS+=	glade-[0-9]*

#.include "../../databases/libgda/buildlink3.mk"
#.include "../../databases/libgnomedb/buildlink3.mk"
.include "../../devel/gail/buildlink3.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../print/libgnomeprintui/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
