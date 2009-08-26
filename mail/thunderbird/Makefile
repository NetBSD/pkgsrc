# $NetBSD: Makefile,v 1.38 2009/08/26 20:22:52 sno Exp $

MOZILLA=		thunderbird
COMMENT=		Mozilla mail client
PKGREVISION=		1

MOZILLA_USE_GTK2=	# yes
MOZILLA_USE_XFT=	YES

# thunderbird passes LD_LIBRARY_PATH to mime handlers, making them fail:
# https://bugzilla.mozilla.org/show_bug.cgi?id=392327

.include "../../mail/thunderbird/Makefile-thunderbird.common"
.include "../../mk/bsd.pkg.mk"
