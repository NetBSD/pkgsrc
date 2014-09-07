# $NetBSD: Makefile,v 1.5 2014/09/07 12:26:43 obache Exp $

PKGNAME=	suse_libcurl-${SUSE_VERSION}
PKGREVISION=	3
CATEGORIES=	emulators
RPMUPDPKGS+=	libcurl4-7.32.0-2.23.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for libcurl

EMUL_MODULES.linux=	krb5 openssl openldap libidn libssh

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
