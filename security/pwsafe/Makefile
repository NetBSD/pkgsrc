# $NetBSD: Makefile,v 1.23 2026/01/23 05:48:47 wiz Exp $

DISTNAME=		pwsafe-0.2.0
PKGREVISION=		11
CATEGORIES=		security
MASTER_SITES=		#

MAINTAINER=		mishka@NetBSD.org
#HOMEPAGE=		http://nsd.dyndns.org/pwsafe/
COMMENT=		CLI based PasswordSafe compatible password manager

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake

.include "options.mk"

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
