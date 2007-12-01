# $NetBSD: Makefile,v 1.5 2007/12/01 12:32:13 rillig Exp $
#

DISTNAME=	notification_plugin-0.12.1
PKGNAME=	claws-mail-notification-0.12.1
CATEGORIES=	mail
MASTER_SITES=	http://claws-mail.org/downloads/plugins/
PKGREVISION=	3

MAINTAINER=	smb@NetBSD.org
COMMENT=	Provides various ways to notify the user of new and unread email

DEPENDS+=	claws-mail>=3.0.0:../../mail/claws-mail

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES+=	c

.include "../../mail/claws-mail/Makefile.vers"
.include "../../mail/claws-mail/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
