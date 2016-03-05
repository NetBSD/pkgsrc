# $NetBSD: Makefile,v 1.76 2016/03/05 11:28:55 jperkin Exp $

DISTNAME=	kdepim-4.14.10
PKGNAME=	${DISTNAME:S/-4/4-4/}
PKGREVISION=	2
CATEGORIES=	misc
COMMENT=	Personal Information Management tools for the KDE desktop
MASTER_SITES=	${MASTER_SITE_KDE:=applications/15.04.3/src/}

.include "../../meta-pkgs/kde4/Makefile.kde4"

USE_TOOLS+=	gmake

# BUILD_MAKE_FLAGS+= VERBOSE=1

CMAKE_ARGS+=-DKDEPIM_BUILD_MOBILE=OFF

CHECK_PORTABILITY_SKIP+=ktimetracker/test/booktime-baddate.sh \
		ktimetracker/test/booktime-badduration.sh \
		ktimetracker/test/booktime-badtime.sh \
		ktimetracker/test/booktime-baduid.sh \
		ktimetracker/test/booktime-works.sh \
		ktimetracker/test/delete.sh \
		ktimetracker/test/refresh_on_change.sh \
		ktimetracker/test/version.sh

REPLACE_BASH+=	kmail/kconf_update/kmail-*.sh

REPLACE_PERL+= \
	agents/mailfilteragent/kconf_update/migrate-kmail-filters.pl \
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
	libkpgp/kconf_update/kpgp-3.1-upgrade-address-data.pl

SUBST_CLASSES+=		perlfix
SUBST_STAGE.perlfix=	pre-configure
SUBST_MESSAGE.perlfix=	Fix perl path in cmake script
SUBST_FILES.perlfix=	korganizer/data/ical2vcal.cmake
SUBST_SED.perlfix=	-e 's:@PERL@:${PERL5}:g'

post-install:
	${RM} ${DESTDIR}${PREFIX}/share/icons/oxygen/*/mimetypes/x-mail-distribution-list.png

BUILDLINK_DEPMETHOD.qt4-tools=full

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/grantlee/buildlink3.mk"
.include "../../devel/libkgapi/buildlink3.mk"
.include "../../devel/qjson/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../misc/kdepimlibs4/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../security/libassuan2/buildlink3.mk"
.include "../../security/qca2/buildlink3.mk"
.include "../../sysutils/baloo/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../x11/kde-runtime4/buildlink3.mk"
.include "../../x11/kde-workspace4/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
