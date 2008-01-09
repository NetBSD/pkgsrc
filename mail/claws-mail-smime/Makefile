# $NetBSD: Makefile,v 1.6 2008/01/09 03:55:12 smb Exp $

DISTNAME=	smime-0.7.4
PKGNAME=	claws-mail-smime-0.7.4
CATEGORIES=	mail
MASTER_SITES=	http://claws-mail.org/downloads/plugins/

MAINTAINER=	smb@NetBSD.org
COMMENT=	This plugin handles S/MIME signed and/or encrypted mails

DEPENDS+=	claws-mail-3.2.0{,nb[0-9]*}:../../mail/claws-mail
PLIST_SRC+=	PLIST

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LIBTOOL=	yes
USE_LANGUAGES+=	c

.include "../../mail/claws-mail/Makefile.vers"
.include "../../mail/claws-mail/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../security/gnupg2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
