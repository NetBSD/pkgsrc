# $NetBSD: Makefile,v 1.21 2026/02/06 10:05:11 wiz Exp $

DISTNAME=	kmail-${KAPPSVER}
PKGREVISION=	3
CATEGORIES=	mail

HOMEPAGE=	https://kontact.kde.org/
COMMENT=	KDE mail client
LICENSE=	gnu-lgpl-v2.1 AND gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=6.18.0:../../devel/kf6-kdoctools
DEPENDS+=	akonadi-import-wizard>=${KAPPSVER}:../../mail/akonadi-import-wizard
DEPENDS+=	kmail-account-wizard>=${KAPPSVER}:../../mail/kmail-account-wizard
DEPENDS+=	mbox-importer>=${KAPPSVER}:../../mail/mbox-importer
DEPENDS+=	pim-data-exporter>=${KAPPSVER}:../../misc/pim-data-exporter
DEPENDS+=	pim-sieve-editor>=${KAPPSVER}:../../mail/pim-sieve-editor

USE_TOOLS+=	msgmerge

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mail/ktnef/buildlink3.mk"
.include "../../mail/libksieve/buildlink3.mk"
.include "../../mail/mailcommon/buildlink3.mk"
.include "../../misc/kdepim-runtime/buildlink3.mk"
.include "../../misc/kontactinterface/buildlink3.mk"
.include "../../misc/kf6-kstatusnotifieritem/buildlink3.mk"
.include "../../misc/kf6-kuserfeedback/buildlink3.mk"
.include "../../security/qt6-qtkeychain/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
