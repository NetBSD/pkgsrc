# $NetBSD: Makefile,v 1.47 2005/06/23 14:06:17 shannonjr Exp $

DISTNAME=	kdepim-${_KDE_VERSION}
CATEGORIES=	misc
COMMENT=	Personal Information Management tools for the KDE desktop

.include "../../meta-pkgs/kde3/Makefile.kde3"

USE_DIRS+=		xdg-1.1
USE_PERL=		run
USE_TOOLS+=		bison gawk

PKG_OPTIONS_VAR=	PKG_OPTIONS.kdepim
PKG_SUPPORTED_OPTIONS=	sasl
PKG_SUGGESTED_OPTIONS=	sasl

.include "../../mk/bsd.options.mk"

BUILDLINK_DEPENDS.gpgme+=     gpgme>=0.4.5

REPLACE_PERL=	kmail/kmail-3.1-update-new-mail-notification-settings.pl \
		kmail/kmail-3.1-use-UOID-for-identities.pl \
		kmail/kmail-3.1.4-dont-use-UOID-0-for-any-identity.pl \
		kmail/kmail-3.3-aegypten.pl \
		kmail/kmail-3.3-misc.pl \
		kmail/kmail-3.3-move-identities.pl \
		kmail/kmail-3.3-use-ID-for-accounts.pl \
		kmail/kmail-3.3b1-misc.pl \
		kmail/kmail-pgpidentity.pl \
		kmail/kmail-upd-identities.pl \
		kmail/kmail-3.4-misc.pl \
		kmail/kmail-3.4.1-update-status-filters.pl \
		kmail/upgrade-signature.pl \
		kmail/upgrade-transport.pl \
		libkdenetwork/kpgp-3.1-upgrade-address-data.pl \
		libkpgp/kpgp-3.1-upgrade-address-data.pl

.include "../../meta-pkgs/kde3/kde3.mk"
BUILDLINK_DEPMETHOD.qt3-tools=	full

.if !empty(PKG_OPTIONS:Msasl)
.include "../../security/cyrus-sasl2/buildlink3.mk"
PLIST_SUBST+=	HAVE_SASL=""
.else
PLIST_SUBST+=	HAVE_SASL="@comment "
.endif

.include "../../comms/libmal/buildlink3.mk"
.include "../../comms/pilot-link-libs/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../devel/librfuncs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
