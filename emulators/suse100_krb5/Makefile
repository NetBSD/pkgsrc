# $NetBSD: Makefile,v 1.2 2014/09/07 12:26:39 obache Exp $

PKGNAME=		suse_krb5-${SUSE_VERSION}
CATEGORIES=		emulators
DISTFILES=		krb5-1.4.1-5.11.${SUSE_ARCH}.rpm		\
			libcom_err-1.38-4.3.${SUSE_ARCH}.rpm

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Linux compatibility package for kerberos libraries

EMUL_MODULES.linux=	base

.include "../../emulators/suse100_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
