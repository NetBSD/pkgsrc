# $NetBSD: Makefile,v 1.83 2021/07/13 12:35:10 nia Exp $
#

PLUGIN_NAME=    newmail

.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Write log file info on arriving email

TOOLS_BROKEN+=		perl
CONFIGURE_ARGS+=	--enable-${PLUGIN_NAME}-plugin

DEPENDS+=	claws-mail-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail

.include "../../mk/bsd.pkg.mk"
