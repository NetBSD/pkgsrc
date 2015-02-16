# $NetBSD: Makefile,v 1.4 2015/02/16 10:15:47 jperkin Exp $

PKGNAME=	suse_cyrus-sasl-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	cyrus-sasl-2.1.25-28.1.2.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for Cyrus SASL

EMUL_MODULES.linux=	base openssl

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
