# $NetBSD: Makefile,v 1.43 2016/08/03 10:23:03 adam Exp $
#

PLUGIN_NAME=    attachwarner
PKGREVISION= 2
.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Warns if a message mentions an attachment without attaching files

CONFIGURE_ARGS+= --enable-${PLUGIN_NAME}-plugin

DEPENDS+=	claws-mail-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail

.include "../../mk/bsd.pkg.mk"
