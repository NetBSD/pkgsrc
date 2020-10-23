# $NetBSD: Makefile,v 1.30 2020/10/23 09:21:00 tnn Exp $

DISTNAME=	pam_yubico-2.17
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	18
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
