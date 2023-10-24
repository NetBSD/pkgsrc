# $NetBSD: Makefile,v 1.3 2023/10/24 22:11:09 wiz Exp $

GITHUB_PROJECT=	libtpms
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	libtpms-0.9.6
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=stefanberger/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/stefanberger/libtpms/
COMMENT=	Library for TPM (Trusted Platform Module) 1.2/2.0 emulation
LICENSE=	libtpms-license

USE_LIBTOOL=	yes
USE_TOOLS+=	automake gmake pkg-config
USE_LANGUAGES=	c c++

GNU_CONFIGURE=		yes
CONFIGURE_SCRIPT=	autogen.sh
CONFIGURE_ARGS+=	--with-tpm2
CONFIGURE_ARGS+=	--with-openssl

PKGCONFIG_OVERRIDE+=	libtpms.pc.in

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
