# $NetBSD: Makefile,v 1.5 2008/01/09 03:55:12 smb Exp $
#

DISTNAME=	synce_plugin-0.7.3
PKGNAME=	claws-mail-synce_plugin-0.7.3
CATEGORIES=	mail
MASTER_SITES=	http://claws-mail.org/downloads/plugins/

MAINTAINER=	smb@NetBSD.org
COMMENT=	Synchronize addressbook of a Windows CE with Claws Mail

DEPENDS+=	claws-mail-3.2.0{,nb[0-9]*}:../../mail/claws-mail

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES+=	c

.include "../../mail/claws-mail/Makefile.vers"
.include "../../comms/synce-libsynce/buildlink3.mk"
.include "../../comms/synce-librapi2/buildlink3.mk"
.include "../../mail/claws-mail/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
