# $NetBSD: Makefile,v 1.2 2024/12/05 08:29:16 vins Exp $
#

DISTNAME=	opensmtpd-tables-1.1
CATEGORIES=	meta-pkgs mail
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	vins@NetBSD.org
COMMENT=	OpenSMTPD extra tables collection

META_PACKAGE=	yes

DEPENDS+=	opensmtpd-table-passwd-[0-9]*:../../mail/opensmtpd-table-passwd
DEPENDS+=	opensmtpd-table-socketmap-[0-9]*:../../mail/opensmtpd-table-socketmap

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
