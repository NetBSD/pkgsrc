# $NetBSD: Makefile,v 1.42 2016/08/03 10:23:04 adam Exp $
#

PLUGIN_NAME=    mailmbox
PKGREVISION= 2
.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Handles mailboxes in mbox format

CONFIGURE_ARGS+= --enable-${PLUGIN_NAME}-plugin

DEPENDS+=	claws-mail-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail

.include "../../mk/bsd.pkg.mk"
