# $NetBSD: Makefile,v 1.1 1998/10/02 14:46:07 tv Exp $
#

DISTNAME=	libtool-1.2
PKGNAME=	pkglibtool-1.2
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

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/libtool ${PREFIX}/bin/pkglibtool

.include "../../mk/bsd.pkg.mk"
