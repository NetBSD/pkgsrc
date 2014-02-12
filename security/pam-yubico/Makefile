# $NetBSD: Makefile,v 1.8 2014/02/12 23:18:35 tron Exp $

DISTNAME=	pam_yubico-2.13
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://yubico-pam.googlecode.com/files/

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://code.google.com/p/yubico-pam/
COMMENT=	Pluggable Authentication Module for Yubikey validation

LICENSE=	modified-bsd

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config
USE_LIBTOOL=		yes

.include "../../security/libyubikey/buildlink3.mk"
.include "../../security/ykclient/buildlink3.mk"
.include "../../security/ykpers/buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
