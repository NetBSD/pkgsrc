# $NetBSD: Makefile,v 1.1.1.1 2009/11/28 21:59:52 tnn Exp $

MOZILLA=		thunderbird
COMMENT=		Mozilla mail client

MOZILLA_USE_GTK2=	# yes
MOZILLA_USE_XFT=	YES

# thunderbird passes LD_LIBRARY_PATH to mime handlers, making them fail:
# https://bugzilla.mozilla.org/show_bug.cgi?id=392327

.include "../../mail/thunderbird2/Makefile-thunderbird.common"
.include "../../mk/bsd.pkg.mk"
