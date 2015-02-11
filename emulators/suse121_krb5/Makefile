# $NetBSD: Makefile,v 1.4 2015/02/11 09:38:15 obache Exp $

DISTNAME=	suse_krb5-${SUSE_VERSION}
PKGREVISION=	1
CATEGORIES=	emulators
RPMUPDPKGS+=	krb5-1.9.1-24.20.1.${SUSE_ARCH}
RPMPKGS+=	libcom_err2-1.41.14-10.1.2.${SUSE_ARCH}
RPMPKGS+=	libkeyutils1-1.5.3-2.1.2.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for kerberos libraries

EMUL_MODULES.linux=	base

.include "../../emulators/suse121_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
