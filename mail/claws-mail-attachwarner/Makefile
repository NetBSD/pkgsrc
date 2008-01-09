# $NetBSD: Makefile,v 1.6 2008/01/09 03:55:09 smb Exp $
#

DISTNAME=	attachwarner-0.2.10
PKGNAME=	claws-mail-attachwarner-0.2.10
CATEGORIES=	mail
MASTER_SITES=	http://claws-mail.org/downloads/plugins/

MAINTAINER=	smb@NetBSD.org
COMMENT=	Warns if a message mentions an attachment without attaching files

PLIST_SRC+=	PLIST

DEPENDS+=	claws-mail-3.2.0{,nb[0-9]*}:../../mail/claws-mail

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES+=	c

.include "../../mail/claws-mail/Makefile.vers"
.include "../../mail/claws-mail/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
