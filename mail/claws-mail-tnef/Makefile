# $NetBSD: Makefile,v 1.26 2012/09/15 10:05:26 obache Exp $
#

DISTNAME=	tnef_parse-0.3.13
PKGNAME=	claws-mail-tnef-0.3.13
PKGREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://claws-mail.org/downloads/plugins/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Handles TNEF attachments from Outlook

PKG_DESTDIR_SUPPORT=	user-destdir

#PLIST_SRC+=	PLIST

DEPENDS+=	claws-mail-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail

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
