# $NetBSD: Makefile,v 1.35 2009/03/19 15:08:58 ghen Exp $

MOZILLA=		thunderbird
COMMENT=		Mozilla mail client

MOZILLA_USE_GTK2=	# yes
MOZILLA_USE_XFT=	YES

# thunderbird passes LD_LIBRARY_PATH to mime handlers, making them fail:
# https://bugzilla.mozilla.org/show_bug.cgi?id=392327

.include "../../mail/thunderbird/Makefile-thunderbird.common"
.include "../../mk/bsd.pkg.mk"
