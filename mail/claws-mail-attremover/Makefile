# $NetBSD: Makefile,v 1.2 2007/09/18 03:17:26 smb Exp $
#

DISTNAME=att_remover-1.0.7
PKGNAME=claws-mail-att_remover-1.0.7
CATEGORIES=mail
MASTER_SITES=	http://claws-mail.org/downloads/plugins/

MAINTAINER=	smb@NetBSD.org
COMMENT=	Permanently deletes attachments from mail

DEPENDS+=	claws-mail-${CLAWS_VERSION}:../../mail/claws-mail

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES+=	c

.include "../../mail/claws-mail/Makefile.vers"
.include "../../mail/claws-mail/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
