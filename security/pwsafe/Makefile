# $NetBSD: Makefile,v 1.8 2008/06/12 02:14:45 joerg Exp $
#

DISTNAME=		pwsafe-0.2.0
PKGREVISION=		2
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pwsafe/} \
			http://nsd.dyndns.org/pwsafe/releases/

MAINTAINER=		mishka@apk.od.ua
HOMEPAGE=		http://nsd.dyndns.org/pwsafe/
COMMENT=		CLI based PasswordSafe compatible password manager

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "options.mk"

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
