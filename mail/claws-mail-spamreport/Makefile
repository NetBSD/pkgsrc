# $NetBSD: Makefile,v 1.92 2022/10/26 10:31:37 wiz Exp $
#

PLUGIN_NAME=		spam_report
PLUGIN_FILE=		spamreport

PKGREVISION= 5
.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Report spam to various places

TOOLS_BROKEN+=		perl
CONFIGURE_ARGS+=	--enable-${PLUGIN_NAME}-plugin

DEPENDS+=	claws-mail-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail

.include "../../mk/bsd.pkg.mk"
