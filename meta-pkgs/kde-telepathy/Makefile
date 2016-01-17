# $NetBSD: Makefile,v 1.1 2016/01/17 15:05:18 jaapb Exp $

.include "Makefile.common"
DISTNAME=	kde-telepathy-${KTP_VERSION}
PKGREVISION=	2
CATEGORIES=	meta-pkgs chat kde
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://userbase.kde.org/Telepathy
COMMENT=	"meta-package" for KDE Telepathy

DEPENDS+=	ktp-accounts-kcm-${KTP_VERSION}{,nb[0-9]*}:../../chat/ktp-accounts-kcm
DEPENDS+=	ktp-approver-${KTP_VERSION}{,nb[0-9]*}:../../chat/ktp-approver
DEPENDS+=	ktp-auth-handler-${KTP_VERSION}{,nb[0-9]*}:../../chat/ktp-auth-handler
#DEPENDS+=	ktp-call-ui-${KTP_VERSION}{,nb[0-9]*}:../../chat/ktp-call-ui
# this package still has a boost error that needs to be fixed somehow
DEPENDS+=	ktp-common-internals-${KTP_VERSION}{,nb[0-9]*}:../../chat/ktp-common-internals
DEPENDS+=	ktp-contact-list-${KTP_VERSION}{,nb[0-9]*}:../../chat/ktp-contact-list
DEPENDS+=	ktp-contact-runner-${KTP_VERSION}{,nb[0-9]*}:../../chat/ktp-contact-runner
DEPENDS+=	ktp-desktop-applets-${KTP_VERSION}{,nb[0-9]*}:../../chat/ktp-desktop-applets
DEPENDS+=	ktp-filetransfer-handler-${KTP_VERSION}{,nb[0-9]*}:../../chat/ktp-filetransfer-handler
DEPENDS+=	ktp-kded-integration-module-${KTP_VERSION}{,nb[0-9]*}:../../chat/ktp-kded-integration-module
DEPENDS+=	ktp-send-file-${KTP_VERSION}{,nb[0-9]*}:../../chat/ktp-send-file
DEPENDS+=	ktp-text-ui-${KTP_VERSION}{,nb[0-9]*}:../../chat/ktp-text-ui

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
