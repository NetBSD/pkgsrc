# $NetBSD: Makefile,v 1.36 2009/06/19 11:34:31 he Exp $

MOZILLA=		thunderbird
PKGREVISION=		1
COMMENT=		Mozilla mail client

MOZILLA_USE_GTK2=	# yes
MOZILLA_USE_XFT=	YES

# thunderbird passes LD_LIBRARY_PATH to mime handlers, making them fail:
# https://bugzilla.mozilla.org/show_bug.cgi?id=392327

.include "../../mail/thunderbird/Makefile-thunderbird.common"
.include "../../mk/bsd.pkg.mk"
