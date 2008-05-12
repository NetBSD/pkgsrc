# $NetBSD: Makefile,v 1.3 2008/05/12 02:25:40 smb Exp $
#

DISTNAME=	tnef_parse-0.2.3
PKGNAME=	claws-mail-tnef-0.2.3
CATEGORIES=	mail
MASTER_SITES=	http://claws-mail.org/downloads/plugins/
PKGREVISION=	1

MAINTAINER=	smb@NetBSD.org
COMMENT=	Handles TNEF attachments from Outlook

#PLIST_SRC+=	PLIST

DEPENDS+=	claws-mail-3.4.0{,nb[0-9]*}:../../mail/claws-mail

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES+=	c

.include "../../devel/glib2/buildlink3.mk"
.include "../../mail/libytnef/buildlink3.mk"
.include "../../mail/claws-mail/Makefile.vers"
.include "../../mail/claws-mail/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
