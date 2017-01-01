# $NetBSD: Makefile,v 1.46 2017/01/01 16:06:24 adam Exp $
#

PLUGIN_NAME=    mailmbox
PKGREVISION= 3
.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Handles mailboxes in mbox format

CONFIGURE_ARGS+= --enable-${PLUGIN_NAME}-plugin

DEPENDS+=	claws-mail-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail

.include "../../mk/bsd.pkg.mk"
