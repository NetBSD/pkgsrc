# $NetBSD: Makefile,v 1.1.1.1 2012/03/13 15:32:47 pettai Exp $

DISTNAME=	pam_yubico-2.11
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	security
MASTER_SITES=	http://yubico-pam.googlecode.com/files/

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://code.google.com/p/yubico-pam/
COMMENT=	Pluggable Authentication Module for Yubikey validation

LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config
USE_LIBTOOL=		yes

.include "../../security/libyubikey/buildlink3.mk"
.include "../../security/ykclient/buildlink3.mk"
.include "../../security/ykpers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
