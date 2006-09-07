# $NetBSD: Makefile,v 1.14 2006/09/07 20:30:09 smb Exp $
#

DISTNAME=	gtkpod-0.94.0
PKGREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtkpod/}

MAINTAINER=	smb@NetBSD.org
HOMEPAGE=	http://www.gtkpod.org/
COMMENT=	GUI for iPod using GTK2

GNU_CONFIGURE=		yes

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		intltool msgfmt perl:run pkg-config

REPLACE_PERL+=		scripts/mab2vcard

BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.4.0

.include "options.mk"

.include "../../audio/libid3tag/buildlink3.mk"
.include "../../devel/atk/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
