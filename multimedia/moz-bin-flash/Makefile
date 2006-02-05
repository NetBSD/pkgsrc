# $NetBSD: Makefile,v 1.6 2006/02/05 23:10:17 joerg Exp $
.include "../../www/firefox-bin-flash/Makefile.common"

PKGREVISION=	1
COMMENT=	Flash Player plugin for mozilla-bin
MOZ_NAME=	mozilla-linux
MOZ_BIN=	moz-bin

DEPENDS+=	mozilla-bin-[0-9]*:../../www/mozilla-bin

CONFLICTS+=	mozilla-flash-bin-[0-9]*

.include "../../emulators/suse_linux/Makefile.application"
.include "../../mk/bsd.pkg.mk"
