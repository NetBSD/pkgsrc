# $NetBSD: Makefile,v 1.39 2024/05/16 06:15:31 wiz Exp $

DISTNAME=	pam_yubico-2.27
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	4
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=Yubico/}
GITHUB_PROJECT=	yubico-pam
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://opensource.yubico.com/yubico-pam/
COMMENT=	Pluggable Authentication Module for Yubikey validation
LICENSE=	modified-bsd

TOOL_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config autoconf automake autoreconf
USE_LIBTOOL=		yes

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

.include "../../security/libyubikey/buildlink3.mk"
.include "../../security/ykclient/buildlink3.mk"
.include "../../security/ykpers/buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
