# $NetBSD: Makefile,v 1.6 2010/04/10 02:45:03 markd Exp $

DISTNAME=	kdepim-${_KDE_VERSION}
CATEGORIES=	misc
COMMENT=	Personal Information Management tools for the KDE desktop

.include "../../meta-pkgs/kde4/Makefile.kde4"

# BUILD_MAKE_FLAGS+= VERBOSE=1

CMAKE_ARGS+=-DMAL_BASE:STRING=${BUILDLINK_PREFIX.libmal}

CHECK_PORTABILITY_SKIP+=ktimetracker/test/booktime-baddate.sh \
		ktimetracker/test/booktime-badduration.sh \
		ktimetracker/test/booktime-badtime.sh \
		ktimetracker/test/booktime-baduid.sh \
		ktimetracker/test/booktime-works.sh \
		ktimetracker/test/delete.sh \
		ktimetracker/test/refresh_on_change.sh \
		ktimetracker/test/version.sh

REPLACE_PERL+= \
	kalarm/kalarm-1.2.1-general.pl \
	kalarm/kalarm-1.9.5-defaults.pl \
	kalarm/kalarm-2.0.2-general.pl \
	kalarm/kalarm-2.1.5-general.pl \
	kalarm/kalarm-version.pl \
	kmail/kconf_update/kmail-3.1-update-new-mail-notification-settings.pl \
	kmail/kconf_update/kmail-3.1-use-UOID-for-identities.pl \
	kmail/kconf_update/kmail-3.1.4-dont-use-UOID-0-for-any-identity.pl \
	kmail/kconf_update/kmail-3.3-aegypten.pl \
	kmail/kconf_update/kmail-3.3-misc.pl \
	kmail/kconf_update/kmail-3.3-move-identities.pl \
	kmail/kconf_update/kmail-3.3-use-ID-for-accounts.pl \
	kmail/kconf_update/kmail-3.3b1-misc.pl \
	kmail/kconf_update/kmail-3.4-misc.pl \
	kmail/kconf_update/kmail-3.4.1-update-status-filters.pl \
	kmail/kconf_update/kmail-3.5-trigger-flag-migration.pl \
	kmail/kconf_update/kmail-4.0-misc.pl \
	kmail/kconf_update/kmail-pgpidentity.pl \
	kmail/kconf_update/kmail-upd-identities.pl \
	kmail/kconf_update/upgrade-signature.pl \
	kmail/kconf_update/upgrade-transport.pl \
	kresources/kolab/upgrade-resourcetype.pl \
	libkpgp/kpgp-3.1-upgrade-address-data.pl

SUBST_CLASSES+=		perlfix
SUBST_STAGE.perlfix=	pre-configure
SUBST_MESSAGE.perlfix=	Fix perl path in cmake script
SUBST_FILES.perlfix=	korganizer/ical2vcal.cmake
SUBST_SED.perlfix=	-e 's:@PERL@:${PERL5}:g'

BUILDLINK_DEPMETHOD.qt4-tools=full

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../comms/libmal/buildlink3.mk"
.include "../../comms/libopensync/buildlink3.mk"
.include "../../comms/pilot-link-libs/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../misc/kdepimlibs4/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../security/libassuan/buildlink3.mk"
.include "../../security/qca2/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../x11/kdebase-runtime4/buildlink3.mk"
.include "../../x11/kdebase-workspace4/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
