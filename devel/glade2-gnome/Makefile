# $NetBSD: Makefile,v 1.5 2006/02/04 13:43:51 wiz Exp $

.include "../../devel/glade2/Makefile.common"

PKGNAME=	${DISTNAME:S/glade/glade2-gnome/}
PKGREVISION=	3
CATEGORIES+=	gnome

COMMENT+=	and GNOME2

CONFLICTS+=	glade2-[0-9]*

#.include "../../databases/libgda/buildlink3.mk"
#.include "../../databases/libgnomedb/buildlink3.mk"
.include "../../devel/gail/buildlink3.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../print/libgnomeprintui/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
