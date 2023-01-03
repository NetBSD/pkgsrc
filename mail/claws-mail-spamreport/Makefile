# $NetBSD: Makefile,v 1.93 2023/01/03 17:37:47 wiz Exp $
#

PLUGIN_NAME=		spam_report
PLUGIN_FILE=		spamreport

PKGREVISION= 6
.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Report spam to various places

TOOLS_BROKEN+=		perl
CONFIGURE_ARGS+=	--enable-${PLUGIN_NAME}-plugin

DEPENDS+=	claws-mail-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail

.include "../../mk/bsd.pkg.mk"
