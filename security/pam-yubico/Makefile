# $NetBSD: Makefile,v 1.10 2014/11/10 21:55:31 pettai Exp $

DISTNAME=	pam_yubico-2.17
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	security
MASTER_SITES=	http://opensource.yubico.com/yubico-pam/releases/

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://opensource.yubico.com/yubico-pam/
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
