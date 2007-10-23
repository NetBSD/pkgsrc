# $NetBSD: Makefile,v 1.5 2007/10/23 20:16:54 smb Exp $
#

DISTNAME=	rssyl-0.15
PKGNAME=	claws-mail-rssyl-0.15
CATEGORIES=	mail
MASTER_SITES=	http://claws-mail.org/downloads/plugins/
PKGREVISION=	2

MAINTAINER=	smb@NetBSD.org
COMMENT=	Read RSS 1.0, 2.0 and Atom feeds in Claws-Mail

PLIST_SRC+=	PLIST

DEPENDS+=	claws-mail>=3.0.0:../../mail/claws-mail

PLIST_SRC+=	PLIST

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES+=	c

.include "../../mail/claws-mail/Makefile.vers"
.include "../../mail/claws-mail/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
