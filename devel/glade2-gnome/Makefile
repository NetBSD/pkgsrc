# $NetBSD: Makefile,v 1.1.1.1 2004/12/29 12:58:26 jmmv Exp $

.include "../../devel/glade2/Makefile.common"

PKGNAME:=	${PKGNAME:S/glade2/glade2-gnome/}
CATEGORIES+=	gnome

COMMENT+=	and GNOME2

CONFLICTS+=	glade2-[0-9]*

.include "../../databases/libgda/buildlink3.mk"
.include "../../databases/libgnomedb/buildlink3.mk"
.include "../../devel/gail/buildlink3.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../print/libgnomeprintui/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
