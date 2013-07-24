# $NetBSD: Makefile,v 1.44 2013/07/24 15:29:22 drochner Exp $
#

PLUGIN_NAME=    vcalendar
.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Enable vCalendar message handling

USE_TOOLS+=	perl

CONFIGURE_ARGS+= --enable-${PLUGIN_NAME}-plugin
PLIST_SRC+=	PLIST

DEPENDS+=	claws-mail-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail

.include "../../mk/bsd.pkg.mk"
