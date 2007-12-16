# $NetBSD: Makefile,v 1.9 2007/12/16 18:10:54 drochner Exp $

.include "../../devel/glade/Makefile.common"

PKGNAME=	${DISTNAME:S/glade/glade-gnome/}
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
