# $NetBSD: Makefile,v 1.4 1998/08/20 15:16:48 tsarna Exp $
# FreeBSD Id: Makefile,v 1.1.1.1 1998/05/07 15:58:20 vanilla Exp
#

DISTNAME=	libtool-1.2
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
