# $NetBSD: Makefile,v 1.1 2007/08/06 00:33:07 smb Exp $
#

DISTNAME=cachesaver-0.10.5
PKGNAME=claws-mail-cachesaver-0.10.5
CATEGORIES=mail
MASTER_SITES=	http://claws-mail.org/downloads/plugins/

MAINTAINER=	smb@NetBSD.org
COMMENT=	Saves Claws-Mail metadata every 60 seconds

DEPENDS+=	claws-mail>=2.10.0:../../mail/claws-mail

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES+=	c

.include "../../mail/claws-mail/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
