# $NetBSD: Makefile,v 1.7 2007/10/23 20:16:52 smb Exp $
#

DISTNAME=	gtkhtml2_viewer-0.15.2
PKGNAME=	claws-mail-gtkhtml2_viewer-0.15.2
CATEGORIES=	mail
MASTER_SITES=	http://claws-mail.org/downloads/plugins/
PKGREVISION=	4

MAINTAINER=	smb@NetBSD.org
COMMENT=	Renders HTML mail using the gtkhtml2 rendering widget

PLIST_SRC+=	PLIST

DEPENDS+=	claws-mail>=3.0.0:../../mail/claws-mail

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES+=	c

.include "../../mail/claws-mail/Makefile.vers"
.include "../../mail/claws-mail/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../www/libgtkhtml/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
