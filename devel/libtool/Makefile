# $NetBSD: Makefile,v 1.6 1999/02/20 22:48:27 hubertf Exp $
#

DISTNAME=	libtool-1.2
# XXX should change back to libtool with next release; this differentiates
# libtool from pkg-customized libtool, the latter under the "libtool-1.2" name
PKGNAME=	glibtool-1.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	tv@netbsd.org
HOMEPAGE=	http://www.profitpress.com/libtool/

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		INSTALL_DATA="${INSTALL_DATA}"
.if !exists(/usr/libexec/ld.so) && !exists(/usr/libexec/ld.elf_so)
CONFIGURE_ARGS=	--disable-shared
.endif

.include "../../mk/bsd.pkg.mk"
