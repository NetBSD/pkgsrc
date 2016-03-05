# $NetBSD: Makefile,v 1.73 2016/03/05 11:27:51 jperkin Exp $

DISTNAME=	kdepimlibs-4.14.10
PKGNAME=	${DISTNAME:S/-4/4-4/}
PKGREVISION=	1
CATEGORIES=	misc
COMMENT=	Support libraries for PIM for the KDE integrated X11 desktop
MASTER_SITES=	${MASTER_SITE_KDE:=applications/15.04.3/src/}

.include "../../meta-pkgs/kde4/Makefile.kde4"

SUBST_CLASSES+=			phononrelpath
SUBST_STAGE.phononrelpath=	post-configure
SUBST_MESSAGE.phononrelpath=	Fixing phonon RELWITHDEBINFO path
SUBST_FILES.phononrelpath=	_KDE_build/CMakeFiles/Export/${LOCALBASE:S^/^_^}/lib/cmake/KdepimLibs/KDEPimLibsLibraryTargetsWithPrefix-${TARGET_NAME}.cmake
SUBST_SED.phononrelpath=	-e 's:[^"]*/\.buildlink/lib/libphonon\.so::'

CMAKE_DEPENDENCIES_REWRITE= _KDE_build/KDEPimLibsDependencies.cmake

CMAKE_ARGS+=	-DKDE4_BUILD_TESTS:BOOL=OFF

# for strcasecmp
CFLAGS.SunOS+=	-D__EXTENSIONS__

REPLACE_PERL+= mailtransport/kconf_update/migrate-transports.pl

BUILDLINK_API_DEPENDS.akonadi+=	akonadi>=1.8.51

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../databases/openldap-client/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.if ${OPSYS} == "Linux"
.include "../../devel/libuuid/buildlink3.mk"
.endif
.include "../../devel/qjson/buildlink3.mk"
.include "../../mail/akonadi/buildlink3.mk"
#.include "../../misc/nepomuk-core/buildlink3.mk"
.include "../../security/cyrus-sasl/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../time/libical/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
