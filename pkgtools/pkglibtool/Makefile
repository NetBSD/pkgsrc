# $NetBSD: Makefile,v 1.10 1999/07/17 19:26:45 tron Exp $
#

DISTNAME=	libtool-1.2
PKGNAME=	pkglibtool-1.2p2
CATEGORIES=	pkgtools devel
MASTER_SITES=	${MASTER_SITE_GNU:=libtool/}

MAINTAINER=	tv@netbsd.org
HOMEPAGE=	http://www.profitpress.com/libtool/

GNU_CONFIGURE=	yes
.if !exists(/usr/libexec/ld.so) && !exists(/usr/libexec/ld.elf_so)
CONFIGURE_ARGS=	--disable-shared
.endif

BINARY=		${PKGNAME:S/-/-${OBJECT_FMT}-/}
PLIST_SRC=	${WRKDIR}/PLIST

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/libtool ${PREFIX}/bin/${BINARY}
	@${ECHO} >${PLIST_SRC} bin/${BINARY}

.include "../../mk/bsd.pkg.mk"
