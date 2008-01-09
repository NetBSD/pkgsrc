# $NetBSD: Makefile,v 1.6 2008/01/09 03:55:11 smb Exp $
#

DISTNAME=	pdf_viewer-0.8
PKGNAME=	claws-mail-pdf_viewer-0.8
CATEGORIES=	mail
MASTER_SITES=	http://claws-mail.org/downloads/plugins/

MAINTAINER=	smb@NetBSD.org
COMMENT=	Enables the viewing of PDF and PostScript attachments

PLIST_SRC+=	PLIST

DEPENDS+=	claws-mail-3.2.0{,nb[0-9]*}:../../mail/claws-mail

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
