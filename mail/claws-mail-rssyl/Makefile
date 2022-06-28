# $NetBSD: Makefile,v 1.96 2022/06/28 11:34:18 wiz Exp $
#

PLUGIN_NAME=    rssyl

PKGREVISION= 4
.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Read RSS 1.0, 2.0 and Atom feeds in Claws-Mail

TOOLS_BROKEN+=		perl
CONFIGURE_ARGS+=	--enable-${PLUGIN_NAME}-plugin

DEPENDS+=	claws-mail-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
