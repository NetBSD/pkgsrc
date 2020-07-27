# $NetBSD: Makefile,v 1.25 2020/07/27 16:20:45 gdt Exp $

DISTNAME=	pkcs11-helper-1.10
PKGREVISION=	13
CATEGORIES=	security
MASTER_SITES=	https://github.com/downloads/alonbl/pkcs11-helper/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/OpenSC/OpenSC/wiki/pkcs11-helper
COMMENT=	Library that simplifies the interaction with PKCS\#11
LICENSE=	modified-bsd OR gnu-gpl-v2

BROKEN=		"Fails to build with OpenSSL 1.1"

# Not documented, but relatively clear from warnings.
USE_LANGUAGES=		c99
USE_LIBTOOL=		yes
USE_TOOLS+=		autoconf autoreconf gmake pkg-config
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--enable-strict
CONFIGURE_ARGS+=	--enable-pedantic

PKGCONFIG_OVERRIDE+=	lib/libpkcs11-helper-1.pc.in

pre-configure:
	cd ${WRKSRC} && autoreconf

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
