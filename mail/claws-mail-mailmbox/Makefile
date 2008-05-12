# $NetBSD: Makefile,v 1.6 2008/05/12 02:25:40 smb Exp $
#

DISTNAME=	mailmbox-1.14.1
PKGNAME=	claws-mail-mailmbox-1.14.1
CATEGORIES=	mail
MASTER_SITES=	http://claws-mail.org/downloads/plugins/

MAINTAINER=	smb@NetBSD.org
COMMENT=	Handles mailboxes in mbox format

DEPENDS+=	claws-mail-3.4.0{,nb[0-9]*}:../../mail/claws-mail

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES+=	c

.include "../../mail/claws-mail/Makefile.vers"
.include "../../mail/claws-mail/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
