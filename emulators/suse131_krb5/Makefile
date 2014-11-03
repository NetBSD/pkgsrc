# $NetBSD: Makefile,v 1.4 2014/11/03 08:17:47 obache Exp $

PKGNAME=	suse_krb5-${SUSE_VERSION}
PKGREVISION=	2
CATEGORIES=	emulators
RPMUPDPKGS+=	krb5-1.11.3-3.12.1.${SUSE_ARCH}
RPMPKGS+=	libcom_err2-1.42.8-2.1.2.${SUSE_ARCH}
RPMPKGS+=	libkeyutils1-1.5.5-6.1.3.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for kerberos libraries

EMUL_MODULES.linux=	base

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
