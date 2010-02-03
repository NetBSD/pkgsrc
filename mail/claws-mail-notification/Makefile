# $NetBSD: Makefile,v 1.15 2010/02/03 19:45:05 drochner Exp $
#

DISTNAME=	notification_plugin-0.24
PKGNAME=	claws-mail-notification-0.24
CATEGORIES=	mail
MASTER_SITES=	http://claws-mail.org/downloads/plugins/

MAINTAINER=	smb@NetBSD.org
COMMENT=	Provides various ways to notify the user of new and unread email

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	claws-mail-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES+=	c

.include "../../mail/claws-mail/Makefile.vers"
.include "../../mail/claws-mail/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
