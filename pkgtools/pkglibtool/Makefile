# $NetBSD: Makefile,v 1.8 1999/04/14 21:39:04 tron Exp $
#

DISTNAME=	libtool-1.2
PKGNAME=	pkglibtool-1.2p1
CATEGORIES=	pkgtools devel
MASTER_SITES=	${MASTER_SITE_GNU:=libtool/}

MAINTAINER=	tv@netbsd.org
HOMEPAGE=	http://www.profitpress.com/libtool/

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		INSTALL_DATA="${INSTALL_DATA}"
.if !exists(/usr/libexec/ld.so) && !exists(/usr/libexec/ld.elf_so)
CONFIGURE_ARGS=	--disable-shared
.endif

PLIST_SRC=	${WRKDIR}/PLIST

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/libtool ${PREFIX}/bin/${PKGNAME}
	@${ECHO} >${PLIST_SRC} bin/${PKGNAME}

.include "../../mk/bsd.pkg.mk"
