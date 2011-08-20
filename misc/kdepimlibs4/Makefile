# $NetBSD: Makefile,v 1.20 2011/08/20 21:33:28 wiz Exp $

DISTNAME=	kdepimlibs-${_KDE_VERSION}
PKGREVISION=	1
CATEGORIES=	misc
COMMENT=	Support libraries for PIM for the KDE integrated X11 desktop

.include "../../meta-pkgs/kde4/Makefile.kde4"

CMAKE_DEPENDENCIES_REWRITE= _KDE_build/KDEPimLibsDependencies.cmake

REPLACE_PERL+= mailtransport/kconf_update/migrate-transports.pl

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../mk/compiler.mk"
# GCC 4.4 and above needs this
.if !empty(PKGSRC_COMPILER:Mgcc) && !empty(CC_VERSION:Mgcc-4.[4-9]*)
_WRAP_EXTRA_ARGS.CXX+=	-std=c++0x
.endif

.include "../../databases/openldap-client/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../mail/akonadi/buildlink3.mk"
.include "../../security/cyrus-sasl/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../time/libical/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
