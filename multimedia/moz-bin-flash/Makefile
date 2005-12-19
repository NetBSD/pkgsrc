# $NetBSD: Makefile,v 1.5 2005/12/19 11:46:30 salo Exp $
.include "../../www/firefox-bin-flash/Makefile.common"

COMMENT=	Flash Player plugin for mozilla-bin
MOZ_NAME=	mozilla-linux
MOZ_BIN=	moz-bin

DEPENDS+=	mozilla-bin-[0-9]*:../../www/mozilla-bin

CONFLICTS+=	mozilla-flash-bin-[0-9]*

.include "../../emulators/suse_linux/Makefile.application"
.include "../../mk/bsd.pkg.mk"
