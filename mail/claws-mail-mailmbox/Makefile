# $NetBSD: Makefile,v 1.81 2021/07/13 12:35:10 nia Exp $
#

PLUGIN_NAME=    mailmbox

.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Handles mailboxes in mbox format

TOOLS_BROKEN+=		perl
CONFIGURE_ARGS+=	--enable-${PLUGIN_NAME}-plugin

DEPENDS+=	claws-mail-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail

.include "../../mk/bsd.pkg.mk"
