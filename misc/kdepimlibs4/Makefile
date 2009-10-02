# $NetBSD: Makefile,v 1.1.1.1 2009/10/02 21:27:09 markd Exp $

DISTNAME=	kdepimlibs-${_KDE_VERSION}
CATEGORIES=	misc
COMMENT=	Support libraries for PIM for the KDE integrated X11 desktop

.include "../../meta-pkgs/kde4/Makefile.kde4"

PKG_DESTDIR_SUPPORT=	user-destdir

CMAKE_DEPENDENCIES_REWRITE= _KDE_build/KDEPimLibsDependencies.cmake

REPLACE_PERL+= mailtransport/kconf_update/migrate-transports.pl

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../databases/openldap-client/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../mail/akonadi/buildlink3.mk"
.include "../../security/cyrus-sasl/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../time/libical/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
