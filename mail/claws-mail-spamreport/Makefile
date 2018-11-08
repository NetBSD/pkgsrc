# $NetBSD: Makefile,v 1.64 2018/11/08 07:29:37 markd Exp $
#

PLUGIN_NAME=		spam_report
PLUGIN_FILE=		spamreport
.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Report spam to various places

CONFIGURE_ARGS+= --enable-${PLUGIN_NAME}-plugin

DEPENDS+=	claws-mail-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail

.include "../../mk/bsd.pkg.mk"
