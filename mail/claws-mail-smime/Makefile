# $NetBSD: Makefile,v 1.2 2007/08/06 21:41:22 smb Exp $

DISTNAME=smime-0.7.1
PKGNAME=claws-mail-smime-0.7.1
CATEGORIES=mail
MASTER_SITES=	http://claws-mail.org/downloads/plugins/

MAINTAINER=	smb@NetBSD.org
COMMENT=	This plugin handles S/MIME signed and/or encrypted mails
PKGREVISION=	1

DEPENDS+=	claws-mail>=2.10.0:../../mail/claws-mail
PLIST_SRC+=	PLIST

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LIBTOOL=	yes
USE_LANGUAGES+=	c

.include "../../mail/claws-mail/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../security/gnupg2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
