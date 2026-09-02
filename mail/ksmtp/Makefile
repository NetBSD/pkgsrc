# $NetBSD: Makefile,v 1.54 2026/09/02 19:03:18 wiz Exp $

DISTNAME=	ksmtp-${KAPPSVER}
PKGREVISION=	6
CATEGORIES=	mail

HOMEPAGE=	https://community.kde.org/KDE_PIM
COMMENT=	Job-based library to send email through an SMTP server
LICENSE=	gnu-lgpl-v2

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	msgmerge

.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../mail/kmime/buildlink3.mk"
.include "../../security/cyrus-sasl/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
