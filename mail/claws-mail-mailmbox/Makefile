# $NetBSD: Makefile,v 1.82 2021/09/29 19:00:54 adam Exp $
#

PLUGIN_NAME=    mailmbox

PKGREVISION= 1
.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Handles mailboxes in mbox format

TOOLS_BROKEN+=		perl
CONFIGURE_ARGS+=	--enable-${PLUGIN_NAME}-plugin

DEPENDS+=	claws-mail-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail

.include "../../mk/bsd.pkg.mk"
