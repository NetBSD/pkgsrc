# $NetBSD: Makefile,v 1.5 2007/10/23 20:16:53 smb Exp $
#

DISTNAME=	pdf_viewer-0.6
PKGNAME=	claws-mail-pdf_viewer-0.6
CATEGORIES=	mail
MASTER_SITES=	http://claws-mail.org/downloads/plugins/
PKGREVISION=	2

MAINTAINER=	smb@NetBSD.org
COMMENT=	Enables the viewing of PDF and PostScript attachments

PLIST_SRC+=	PLIST

DEPENDS+=	claws-mail>=3.0.0:../../mail/claws-mail

.include "../../mail/claws-mail/openssl.mk"
.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_TOOLS+=	gs:run
USE_LANGUAGES+=	c

.include "../../mail/claws-mail/Makefile.vers"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mail/claws-mail/buildlink3.mk"
.include "../../print/poppler-glib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
