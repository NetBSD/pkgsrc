# $NetBSD: Makefile,v 1.8 2008/12/16 21:47:47 smb Exp $
#

DISTNAME=	tnef_parse-0.3.2
PKGNAME=	claws-mail-tnef-0.3.2
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://claws-mail.org/downloads/plugins/

MAINTAINER=	smb@NetBSD.org
COMMENT=	Handles TNEF attachments from Outlook

PKG_DESTDIR_SUPPORT=	user-destdir

#PLIST_SRC+=	PLIST

DEPENDS+=	claws-mail-3.6.1{,nb[0-9]*}:../../mail/claws-mail

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES+=	c

.include "../../devel/glib2/buildlink3.mk"
.include "../../mail/libytnef/buildlink3.mk"
.include "../../mail/claws-mail/Makefile.vers"
.include "../../mail/claws-mail/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
