# $NetBSD: Makefile,v 1.52 2017/01/01 16:06:25 adam Exp $
#

PLUGIN_NAME=		spam_report
PLUGIN_FILE=		spamreport
PKGREVISION= 3
.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Report spam to various places

CONFIGURE_ARGS+= --enable-${PLUGIN_NAME}-plugin

DEPENDS+=	claws-mail-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail

.include "../../mk/bsd.pkg.mk"
