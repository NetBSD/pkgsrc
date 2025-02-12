# $NetBSD: Makefile,v 1.47 2025/02/12 06:44:33 ryoon Exp $

DISTNAME=	kldap-${KAPPSVER}
PKGREVISION=	7
CATEGORIES=	databases

HOMEPAGE=	https://community.kde.org/KDE_PIM
COMMENT=	LDAP access API for KDE
LICENSE=	gnu-lgpl-v2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge

LDFLAGS.SunOS+=	-lsocket

.include "../../databases/openldap-client/buildlink3.mk"
.include "../../devel/kio/buildlink3.mk"
.include "../../security/cyrus-sasl/buildlink3.mk"
.include "../../security/qt5-qtkeychain/buildlink3.mk"
.include "../../textproc/kcompletion/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
