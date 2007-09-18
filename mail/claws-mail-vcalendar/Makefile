# $NetBSD: Makefile,v 1.3 2007/09/18 03:17:32 smb Exp $
#

DISTNAME=vcalendar-1.98
PKGNAME=claws-mail-vcalendar-1.98
CATEGORIES=mail
MASTER_SITES=	http://claws-mail.org/downloads/plugins/

MAINTAINER=	smb@NetBSD.org
COMMENT=	Enable vCalendar message handling

#PLIST_SRC+=	PLIST

DEPENDS+=	claws-mail-${CLAWS_VERSION}:../../mail/claws-mail

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES+=	c

.include "../../mail/claws-mail/Makefile.vers"
.include "../../mail/claws-mail/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
