# $NetBSD: Makefile,v 1.4 2007/10/23 20:16:51 smb Exp $
#

DISTNAME=	att_remover-1.0.7
PKGNAME=	claws-mail-att_remover-1.0.7
CATEGORIES=	mail
MASTER_SITES=	http://claws-mail.org/downloads/plugins/
PKGREVISION=	2

MAINTAINER=	smb@NetBSD.org
COMMENT=	Permanently deletes attachments from mail

DEPENDS+=	claws-mail>=3.0.0:../../mail/claws-mail

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES+=	c

.include "../../mail/claws-mail/Makefile.vers"
.include "../../mail/claws-mail/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
