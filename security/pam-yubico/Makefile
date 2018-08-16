# $NetBSD: Makefile,v 1.20 2018/08/16 18:55:10 adam Exp $

DISTNAME=	pam_yubico-2.17
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	9
CATEGORIES=	security
MASTER_SITES=	http://opensource.yubico.com/yubico-pam/releases/

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://opensource.yubico.com/yubico-pam/
COMMENT=	Pluggable Authentication Module for Yubikey validation

LICENSE=	modified-bsd

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config
USE_LIBTOOL=		yes

# Workaround a bug with NetBSD's openpam
# The bug is described in PR security/39313
#
CFLAGS.NetBSD+=		-DNO_STATIC_MODULES

.include "../../security/libyubikey/buildlink3.mk"
.include "../../security/ykclient/buildlink3.mk"
.include "../../security/ykpers/buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
