# $NetBSD: Makefile,v 1.36 2012/10/08 23:02:00 adam Exp $
#

DISTNAME=	vcalendar-2.0.13
PKGNAME=	claws-mail-vcalendar-2.0.13
PKGREVISION=	4
CATEGORIES=	mail
MASTER_SITES=	http://claws-mail.org/downloads/plugins/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Enable vCalendar message handling

#PLIST_SRC+=	PLIST

DEPENDS+=	claws-mail-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES+=	c

.include "../../mail/claws-mail/Makefile.vers"
.include "../../mail/claws-mail/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
