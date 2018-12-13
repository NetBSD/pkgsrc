# $NetBSD: Makefile,v 1.68 2018/12/13 19:52:07 adam Exp $
#

PLUGIN_NAME=		spam_report
PLUGIN_FILE=		spamreport
PKGREVISION= 4
.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Report spam to various places

CONFIGURE_ARGS+= --enable-${PLUGIN_NAME}-plugin

DEPENDS+=	claws-mail-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail

.include "../../mk/bsd.pkg.mk"
