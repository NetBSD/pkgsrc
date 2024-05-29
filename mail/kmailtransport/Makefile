# $NetBSD: Makefile,v 1.8 2024/05/29 16:33:21 adam Exp $

DISTNAME=	kmailtransport-${KAPPSVER}
PKGREVISION=	2
CATEGORIES=	mail

HOMEPAGE=	https://community.kde.org/KDE_PIM
COMMENT=	Mail Transport Service
LICENSE=	gnu-lgpl-v2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge

# generation of kded.moc fails when ${PREFIX}/include in the moc include path
SUBST_CLASSES+=		fix-moc
SUBST_STAGE.fix-moc=	post-configure
SUBST_MESSAGE.fix-moc=	Cleaning up MOC includes
SUBST_FILES.fix-moc=	_KDE_build/src/kmailtransportakonadi/plugins/CMakeFiles/mailtransport_akonadiplugin_autogen.dir/AutogenInfo.json
SUBST_FILES.fix-moc+=	_KDE_build/src/kmailtransport/plugins/smtp/CMakeFiles/mailtransport_smtpplugin_autogen.dir/AutogenInfo.json
SUBST_NOOP_OK.fix-moc=	yes
SUBST_SED.fix-moc=	-e 's;"${PREFIX}/include",;;g'

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/libkgapi/buildlink3.mk"
.include "../../devel/kcmutils/buildlink3.mk"
.include "../../mail/akonadi-mime/buildlink3.mk"
.include "../../mail/ksmtp/buildlink3.mk"
.include "../../security/cyrus-sasl/buildlink3.mk"
.include "../../security/qt5-qtkeychain/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
