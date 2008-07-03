# $NetBSD: Makefile,v 1.10 2008/07/03 18:40:09 smb Exp $
#

DISTNAME=	pdf_viewer-0.9.1
PKGNAME=	claws-mail-pdf_viewer-0.9.1
PKGREVISION=1
CATEGORIES=	mail
MASTER_SITES=	http://claws-mail.org/downloads/plugins/

MAINTAINER=	smb@NetBSD.org
COMMENT=	Enables the viewing of PDF and PostScript attachments

PKG_DESTDIR_SUPPORT=	user-destdir

LICENSE=gplv2-and-gplv3
RESTRICTED=gpl-incompatibility
NO_BIN_ON_FTP=${RESTRICTED}
NO_BIN_ON_CDROM=${RESTRICTED}

PLIST_SRC+=	PLIST

DEPENDS+=	claws-mail-3.4.0{,nb[0-9]*}:../../mail/claws-mail

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
