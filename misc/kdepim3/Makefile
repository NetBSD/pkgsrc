# $NetBSD: Makefile,v 1.29 2004/04/20 13:29:12 markd Exp $

DISTNAME=	kdepim-${_KDE_VERSION}
CATEGORIES=	misc
COMMENT=	Personal Information Management tools for the KDE desktop

.include "../../meta-pkgs/kde3/Makefile.kde3"

USE_BUILDLINK3=		YES
USE_DIRS+=		xdg-1.1
USE_PERL=		run

REPLACE_PERL=	kmail/kmail-3.1-update-new-mail-notification-settings.pl \
		kmail/kmail-3.1-use-UOID-for-identities.pl \
		kmail/kmail-3.1.4-dont-use-UOID-0-for-any-identity.pl \
		kmail/kmail-pgpidentity.pl \
		kmail/kmail-upd-identities.pl \
		kmail/upgrade-signature.pl \
		kmail/upgrade-transport.pl \
		libkdenetwork/kpgp-3.1-upgrade-address-data.pl

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../comms/libmal/buildlink3.mk"
.include "../../comms/pilot-link-libs/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
