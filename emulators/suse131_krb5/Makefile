# $NetBSD: Makefile,v 1.1 2013/12/05 11:42:15 obache Exp $

DISTNAME=	suse_krb5-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	krb5-1.11.3-3.1.3.${SUSE_ARCH}
RPMPKGS+=	libcom_err2-1.42.8-2.1.2.${SUSE_ARCH}
RPMPKGS+=	libkeyutils1-1.5.5-6.1.3.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for kerberos libraries

EMUL_MODULES.linux=	base

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
