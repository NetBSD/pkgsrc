# $NetBSD: Makefile,v 1.66 2019/07/20 22:46:28 wiz Exp $
#

PLUGIN_NAME=    newmail
PKGREVISION= 6
.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Write log file info on arriving email

CONFIGURE_ARGS+= --enable-${PLUGIN_NAME}-plugin

DEPENDS+=	claws-mail-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail

.include "../../mk/bsd.pkg.mk"
