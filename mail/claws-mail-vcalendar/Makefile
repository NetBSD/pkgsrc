# $NetBSD: Makefile,v 1.2 2007/08/16 23:14:17 smb Exp $
#

DISTNAME=vcalendar-1.96
PKGNAME=claws-mail-vcalendar-1.96
CATEGORIES=mail
MASTER_SITES=	http://claws-mail.org/downloads/plugins/
PKGREVISION=	1

MAINTAINER=	smb@NetBSD.org
COMMENT=	Enable vCalendar message handling

#PLIST_SRC+=	PLIST

DEPENDS+=	claws-mail>=2.10.0:../../mail/claws-mail

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES+=	c

.include "../../mail/claws-mail/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
