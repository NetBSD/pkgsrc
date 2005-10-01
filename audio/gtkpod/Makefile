# $NetBSD: Makefile,v 1.1.1.1 2005/10/01 13:29:52 smb Exp $
#

DISTNAME=	gtkpod-0.94.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtkpod/}

MAINTAINER=	smb@netbsd.org
HOMEPAGE=	http://gtkpod.sourceforge.net/
COMMENT=	GUI for iPod using GTK2

BUILD_USES_MSGFMT=	yes

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes

USE_TOOLS+=	pkg-config
USE_LIBTOOL=	yes

BUILDLINK_DEPENDS.gtk2+=	gtk2+>=2.4.0

.include "../../audio/libid3tag/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/atk/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
