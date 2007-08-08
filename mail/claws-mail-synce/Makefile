# $NetBSD: Makefile,v 1.1 2007/08/08 13:22:30 smb Exp $
#

DISTNAME=synce_plugin-0.7.1
PKGNAME=claws-mail-synce_plugin-0.7.1
CATEGORIES=mail
MASTER_SITES=	http://claws-mail.org/downloads/plugins/

MAINTAINER=	smb@NetBSD.org
COMMENT=	Extends filtering by permitting invocatio of Perl scripts

DEPENDS+=	claws-mail>=2.10.0:../../mail/claws-mail

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES+=	c

.include "../../comms/synce-libsynce/buildlink3.mk"
.include "../../comms/synce-librapi2/buildlink3.mk"
.include "../../mail/claws-mail/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
