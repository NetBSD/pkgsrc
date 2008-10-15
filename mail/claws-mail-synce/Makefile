# $NetBSD: Makefile,v 1.10 2008/10/15 16:22:03 smb Exp $
#

DISTNAME=	synce_plugin-0.7.4
PKGNAME=	claws-mail-synce_plugin-0.7.4
CATEGORIES=	mail
MASTER_SITES=	http://claws-mail.org/downloads/plugins/

MAINTAINER=	smb@NetBSD.org
COMMENT=	Synchronize addressbook of a Windows CE with Claws Mail

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	claws-mail-3.6.1{,nb[0-9]*}:../../mail/claws-mail

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES+=	c

.include "../../mail/claws-mail/Makefile.vers"
.include "../../comms/synce-libsynce/buildlink3.mk"
.include "../../comms/synce-librapi2/buildlink3.mk"
.include "../../mail/claws-mail/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
