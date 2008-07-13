# $NetBSD: Makefile,v 1.8 2008/07/13 22:34:20 smb Exp $
#
PKG_DESTDIR_SUPPORT=	user-destdir

PLUGIN_NAME=	spamassassin
PLUG_VER=	3.5.0
.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	smb@NetBSD.org
COMMENT=	Enables the scanning of incoming mail using SpamAssassin

CONFIGURE_ARGS+=	--enable-${PLUGIN_NAME}-plugin

DEPENDS+=	claws-mail-3.5.0{,nb[0-9]*}:../../mail/claws-mail
DEPENDS+=	spamassassin>=3.2.4nb1:../../mail/spamassassin

.include "../../mail/claws-mail/Makefile.vers"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
