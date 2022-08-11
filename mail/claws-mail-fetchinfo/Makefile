# $NetBSD: Makefile,v 1.86 2022/08/11 05:08:56 gutteridge Exp $
#

PLUGIN_NAME=    fetchinfo

PKGREVISION= 4
.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Inserts headers containing some download information

TOOLS_BROKEN+=		perl
CONFIGURE_ARGS+=	--enable-${PLUGIN_NAME}-plugin

DEPENDS+=	claws-mail-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail

.include "../../mk/bsd.pkg.mk"
