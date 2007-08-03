# $NetBSD: Makefile,v 1.1 2007/08/03 02:34:49 smb Exp $
#

DISTNAME=notification_plugin-0.11
PKGNAME=claws-mail-notification-0.11
CATEGORIES=mail
MASTER_SITES=	http://claws-mail.org/downloads/plugins/

MAINTAINER=	smb@NetBSD.org
COMMENT=	Provides various ways to notify the user of new and unread email

DEPENDS+=	claws-mail>=2.10.0:../../mail/claws-mail

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=             pkg-config
USE_LANGUAGES+=	c

.include "../../mail/claws-mail/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
