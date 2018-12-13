# $NetBSD: Makefile,v 1.63 2018/12/13 19:52:06 adam Exp $
#

PLUGIN_NAME=    attachwarner
PKGREVISION= 4
.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Warns if a message mentions an attachment without attaching files

CONFIGURE_ARGS+= --enable-${PLUGIN_NAME}-plugin

DEPENDS+=	claws-mail-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail

.include "../../mk/bsd.pkg.mk"
