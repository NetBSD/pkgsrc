# $NetBSD: Makefile,v 1.1 2024/12/05 00:58:05 vins Exp $
#

DISTNAME=	opensmtpd-tables-1.0
CATEGORIES=	meta-pkgs mail
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	vins@NetBSD.org
COMMENT=	OpenSMTPD extra tables collection

DEPENDS+=	opensmtpd-table-ldap-[0-9]*:../../mail/opensmtpd-table-ldap
DEPENDS+=	opensmtpd-table-mysql-[0-9]*:../../mail/opensmtpd-table-mysql
DEPENDS+=	opensmtpd-table-passwd-[0-9]*:../../mail/opensmtpd-table-passwd
DEPENDS+=	opensmtpd-table-postgres-[0-9]*:../../mail/opensmtpd-table-postgres
DEPENDS+=	opensmtpd-table-redis-[0-9]*:../../mail/opensmtpd-table-redis
DEPENDS+=	opensmtpd-table-socketmap-[0-9]*:../../mail/opensmtpd-table-socketmap
DEPENDS+=	opensmtpd-table-sqlite-[0-9]*:../../mail/opensmtpd-table-sqlite

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
