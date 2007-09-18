# $NetBSD: Makefile,v 1.2 2007/09/18 03:17:31 smb Exp $
#

DISTNAME=synce_plugin-0.7.2
PKGNAME=claws-mail-synce_plugin-0.7.2
CATEGORIES=mail
MASTER_SITES=	http://claws-mail.org/downloads/plugins/

MAINTAINER=	smb@NetBSD.org
COMMENT=	Extends filtering by permitting invocatio of Perl scripts

DEPENDS+=	claws-mail-${CLAWS_VERSION}:../../mail/claws-mail

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
