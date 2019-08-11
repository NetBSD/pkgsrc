# $NetBSD: Makefile,v 1.80 2019/08/11 13:21:25 wiz Exp $
#

PLUGIN_NAME=    vcalendar
PKGREVISION= 10
.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Enable vCalendar message handling

USE_TOOLS+=	perl

CONFIGURE_ARGS+= --enable-${PLUGIN_NAME}-plugin

DEPENDS+=	claws-mail-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail

.include "../../time/libical/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
