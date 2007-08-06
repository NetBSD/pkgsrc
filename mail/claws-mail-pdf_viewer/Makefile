# $NetBSD: Makefile,v 1.2 2007/08/06 21:41:22 smb Exp $
#

DISTNAME=pdf_viewer-0.5
PKGNAME=claws-mail-pdf_viewer-0.5
CATEGORIES=mail
MASTER_SITES=	http://claws-mail.org/downloads/plugins/

MAINTAINER=	smb@NetBSD.org
COMMENT=	Enables the viewing of PDF and PostScript attachments
PKGREVISION=	1

PLIST_SRC+=	PLIST

DEPENDS+=	claws-mail>=2.10.0:../../mail/claws-mail

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_TOOLS+=	gs:run
USE_LANGUAGES+=	c

.include "../../devel/glib2/buildlink3.mk"
.include "../../mail/claws-mail/buildlink3.mk"
.include "../../print/poppler-glib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
