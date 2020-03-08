# $NetBSD: Makefile,v 1.72 2020/03/08 16:50:21 wiz Exp $
#

PLUGIN_NAME=    attachwarner

PKGREVISION= 3
.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Warns if a message mentions an attachment without attaching files

CONFIGURE_ARGS+=	--enable-${PLUGIN_NAME}-plugin

DEPENDS+=	claws-mail-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail

.include "../../mk/bsd.pkg.mk"
