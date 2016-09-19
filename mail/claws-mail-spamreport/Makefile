# $NetBSD: Makefile,v 1.50 2016/09/19 13:04:23 wiz Exp $
#

PLUGIN_NAME=		spam_report
PLUGIN_FILE=		spamreport
PKGREVISION= 1
.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Report spam to various places

CONFIGURE_ARGS+= --enable-${PLUGIN_NAME}-plugin

DEPENDS+=	claws-mail-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail

.include "../../mk/bsd.pkg.mk"
