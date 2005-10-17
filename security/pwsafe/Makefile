# $NetBSD: Makefile,v 1.3 2005/10/17 10:22:37 wiz Exp $
#

DISTNAME=		pwsafe-0.2.0
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pwsafe/} \
			http://nsd.dyndns.org/pwsafe/releases/

MAINTAINER=		mishka@apk.od.ua
HOMEPAGE=		http://nsd.dyndns.org/pwsafe/
COMMENT=		CLI based PasswordSafe compatible password manager

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "options.mk"

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
