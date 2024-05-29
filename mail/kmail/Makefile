# $NetBSD: Makefile,v 1.8 2024/05/29 16:33:21 adam Exp $

DISTNAME=	kmail-${KAPPSVER}
PKGREVISION=	2
CATEGORIES=	mail

HOMEPAGE=	https://kontact.kde.org/
COMMENT=	KDE mail client
LICENSE=	gnu-lgpl-v2.1 AND gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools
DEPENDS+=	akonadi-import-wizard>=${KAPPSVER}:../../mail/akonadi-import-wizard
DEPENDS+=	kmail-account-wizard>=${KAPPSVER}:../../mail/kmail-account-wizard
DEPENDS+=	mbox-importer>=${KAPPSVER}:../../mail/mbox-importer
DEPENDS+=	pim-data-exporter>=${KAPPSVER}:../../misc/pim-data-exporter
DEPENDS+=	pim-sieve-editor>=${KAPPSVER}:../../mail/pim-sieve-editor

USE_TOOLS+=	msgmerge

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mail/ktnef/buildlink3.mk"
.include "../../mail/libksieve/buildlink3.mk"
.include "../../mail/mailcommon/buildlink3.mk"
.include "../../misc/kdepim-runtime/buildlink3.mk"
.include "../../misc/kontactinterface/buildlink3.mk"
.include "../../misc/kuserfeedback/buildlink3.mk"
.include "../../security/qt5-qtkeychain/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
