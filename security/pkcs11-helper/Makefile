# $NetBSD: Makefile,v 1.37 2023/11/08 13:20:49 wiz Exp $

DISTNAME=	pkcs11-helper-1.27.0
PKGREVISION=	10
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=OpenSC/}
GITHUB_RELEASE=	${DISTNAME:R}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/OpenSC/pkcs11-helper
COMMENT=	Library that simplifies the interaction with PKCS11
LICENSE=	modified-bsd OR gnu-gpl-v2

# Not documented, but relatively clear from warnings.
USE_LANGUAGES=		c99
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--enable-strict
CONFIGURE_ARGS+=	--enable-pedantic

PKGCONFIG_OVERRIDE+=	lib/libpkcs11-helper-1.pc.in

.include "options.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
