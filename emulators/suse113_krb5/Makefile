# $NetBSD: Makefile,v 1.1.1.1 2010/09/24 01:27:59 chs Exp $

DISTNAME=	suse_krb5-${SUSE_VERSION}
CATEGORIES=	emulators
DISTFILES=	krb5-1.8.1-4.3.${SUSE_ARCH}.rpm		\
		libcom_err2-1.41.11-1.11.${SUSE_ARCH}.rpm

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for kerberos libraries

EMUL_MODULES.linux=	base

.include "../../emulators/suse113_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
