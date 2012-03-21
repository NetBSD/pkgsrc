# $NetBSD: Makefile,v 1.1.1.1 2012/03/21 13:37:45 obache Exp $

DISTNAME=	suse_libcurl-${SUSE_VERSION}
CATEGORIES=	emulators
RPMUPDPKGS+=	libcurl4-7.22.0-2.3.1.${SUSE_ARCH}
RPMPKGS+=	libcares2-1.7.5-10.1.2.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for libcurl

EMUL_MODULES.linux=	krb5 openssl

CONFLICTS+=	suse_base<11.3nb2

.include "../../emulators/suse121_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
