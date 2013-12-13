# $NetBSD: Makefile,v 1.2 2013/12/13 02:13:24 obache Exp $

DISTNAME=	suse_libcurl-${SUSE_VERSION}
PKGREVISION=	1
CATEGORIES=	emulators
RPMUPDPKGS+=	libcurl4-7.32.0-2.4.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for libcurl

EMUL_MODULES.linux=	krb5 openssl openldap libidn libssh

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
