# $NetBSD: Makefile,v 1.74 2020/06/01 20:01:17 rillig Exp $
#

PLUGIN_NAME=    archive

PKGREVISION= 2
.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Adds archiving to Claws-Mail

TOOLS_BROKEN+=		perl
CONFIGURE_ARGS+=	--enable-${PLUGIN_NAME}-plugin

DEPENDS+=	claws-mail-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail

.include "../../archivers/libarchive/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
