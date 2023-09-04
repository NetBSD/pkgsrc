# $NetBSD: Makefile,v 1.1 2023/09/04 11:17:49 vins Exp $
#

DISTNAME=	opensmtpd-filters-1.0
CATEGORIES=	meta-pkgs mail
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	vins@NetBSD.org
COMMENT=	OpenSMTPD filters collection

DEPENDS+=	opensmtpd-filter-dkimsign-[0-9]*:../../mail/opensmtpd-filter-dkimsign
DEPENDS+=	opensmtpd-filter-dnsbl-[0-9]*:../../mail/opensmtpd-filter-dnsbl
DEPENDS+=	opensmtpd-filter-rspamd-[0-9]*:../../mail/opensmtpd-filter-rspamd
DEPENDS+=	opensmtpd-filter-senderscore-[0-9]*:../../mail/opensmtpd-filter-senderscore

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
