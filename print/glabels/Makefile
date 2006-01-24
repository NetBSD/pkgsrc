# $NetBSD: Makefile,v 1.11 2006/01/24 07:32:31 wiz Exp $
#

DISTNAME=		glabels-2.0.2
PKGREVISION=		2
CATEGORIES=		print
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=glabels/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://glabels.sourceforge.net/
COMMENT=		Program for creating labels and business cards for GNOME

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_DIRS+=		gnome2-1.5
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config

.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../print/libgnomeprint/buildlink3.mk"
.include "../../print/libgnomeprintui/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
