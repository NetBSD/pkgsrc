# $NetBSD: Makefile,v 1.11 2016/06/17 17:21:38 tsutsui Exp $

PKGNAME=	suse_libcurl-${SUSE_VERSION}
PKGREVISION=	7
CATEGORIES=	emulators
RPMUPDPKGS+=	libcurl4-7.42.1-2.53.2.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for libcurl

EMUL_MODULES.linux=	krb5 openssl openldap libidn libssh

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
