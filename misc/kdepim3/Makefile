# $NetBSD: Makefile,v 1.127 2016/03/05 11:27:51 jperkin Exp $

DISTNAME=	kdepim-${_KDE_VERSION}
PKGREVISION=	44
CATEGORIES=	misc
COMMENT=	Personal Information Management tools for the KDE desktop

.include "../../meta-pkgs/kde3/Makefile.kde3"

USE_TOOLS+=		bison flex gawk bash:run perl:run pkg-config

BUILDLINK_API_DEPENDS.gpgme+=     gpgme>=0.4.5

REPLACE_BASH+=	kmail/kmail-*.sh

REPLACE_PERL+=	kmail/kmail-3.1-update-new-mail-notification-settings.pl \
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
		kmail/kmail-3.5-trigger-flag-migration.pl \
		kmail/upgrade-signature.pl \
		kmail/upgrade-transport.pl \
		kresources/kolab/upgrade-resourcetype.pl \
		libkpgp/kpgp-3.1-upgrade-address-data.pl

CHECK_PORTABILITY_SKIP+=karm/test/booktime-baddate.sh \
		karm/test/booktime-badduration.sh \
		karm/test/booktime-badtime.sh \
		karm/test/booktime-baduid.sh \
		karm/test/booktime-works.sh \
		karm/test/delete.sh \
		karm/test/refresh_on_change.sh \
		karm/test/version.sh

.include "options.mk"

.include "../../mk/bsd.prefs.mk"

.include "../../meta-pkgs/kde3/kde3.mk"
BUILDLINK_DEPMETHOD.qt3-tools=	full

.include "../../comms/libmal/buildlink3.mk"
.include "../../comms/libopensync/buildlink3.mk"
.include "../../comms/pilot-link-libs/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
