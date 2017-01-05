# $NetBSD: Makefile,v 1.18 2017/01/05 09:39:02 roy Exp $
#

DISTNAME=		pwsafe-0.2.0
PKGREVISION=		9
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pwsafe/} \
			http://nsd.dyndns.org/pwsafe/releases/

MAINTAINER=		mishka@NetBSD.org
HOMEPAGE=		http://nsd.dyndns.org/pwsafe/
COMMENT=		CLI based PasswordSafe compatible password manager

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake

.include "options.mk"

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
