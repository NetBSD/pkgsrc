# $NetBSD: Makefile,v 1.1 2007/08/06 00:33:08 smb Exp $
#

DISTNAME=mailmbox-1.13.1
PKGNAME=claws-mail-mailmbox-1.13.1
CATEGORIES=mail
MASTER_SITES=	http://claws-mail.org/downloads/plugins/

MAINTAINER=	smb@NetBSD.org
COMMENT=	Handles mailboxes in mbox format

DEPENDS+=	claws-mail>=2.10.0:../../mail/claws-mail

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES+=	c

.include "../../mail/claws-mail/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
