# $NetBSD: Makefile,v 1.7 2014/11/03 09:25:56 obache Exp $

PKGNAME=	suse_libcurl-${SUSE_VERSION}
PKGREVISION=	5
CATEGORIES=	emulators
RPMUPDPKGS+=	libcurl4-7.32.0-2.31.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for libcurl

EMUL_MODULES.linux=	krb5 openssl openldap libidn libssh

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
