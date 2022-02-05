# $NetBSD: Makefile,v 1.1 2022/02/05 03:09:26 ryoon Exp $

GITHUB_PROJECT=	libtpms
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	libtpms-0.9.1
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
