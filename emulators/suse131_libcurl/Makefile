# $NetBSD: Makefile,v 1.1 2013/12/05 11:42:15 obache Exp $

DISTNAME=	suse_libcurl-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	libcurl4-7.32.0-2.1.2.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for libcurl

EMUL_MODULES.linux=	krb5 openssl libidn libssh

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
