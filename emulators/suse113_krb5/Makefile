# $NetBSD: Makefile,v 1.3 2011/02/10 02:55:46 chs Exp $

DISTNAME=	suse_krb5-${SUSE_VERSION}
PKGREVISION=	1
CATEGORIES=	emulators
DISTFILES=	krb5-1.8.1-5.3.1.${SUSE_ARCH}.rpm		\
		libcom_err2-1.41.11-1.11.${SUSE_ARCH}.rpm

MAINTAINER=	chs@NetBSD.org
COMMENT=	Linux compatibility package for kerberos libraries

EMUL_MODULES.linux=	base

.include "../../emulators/suse113_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
