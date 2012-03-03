# $NetBSD: Makefile,v 1.20 2012/03/03 00:14:25 wiz Exp $
#
PKG_DESTDIR_SUPPORT=	user-destdir

PLUGIN_NAME=	spamassassin
.include "../../mail/claws-mail/plugins.mk"

PKGREVISION=	2

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Enables the scanning of incoming mail using SpamAssassin

CONFIGURE_ARGS+=	--enable-${PLUGIN_NAME}-plugin

DEPENDS+=	claws-mail-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail
DEPENDS+=	spamassassin>=3.2.5:../../mail/spamassassin

.include "../../mail/claws-mail/Makefile.vers"

.include "../../mk/bsd.pkg.mk"
