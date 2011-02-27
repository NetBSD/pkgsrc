# $NetBSD: Makefile,v 1.1.1.1 2011/02/27 15:46:20 chs Exp $

DISTNAME=	suse_libcurl-${SUSE_VERSION}
CATEGORIES=	emulators
DISTFILES=	libcurl4-7.20.1-3.4.${SUSE_ARCH}.rpm

MAINTAINER=	chs@NetBSD.org
COMMENT=	Linux compatibility package for libcurl

EMUL_MODULES.linux=	krb5 openssl

CONFLICTS+=	suse_base<11.3nb2

.include "../../emulators/suse113_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
