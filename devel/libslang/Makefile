# $NetBSD: Makefile,v 1.7 1998/04/20 11:56:22 frueauf Exp $
# FreeBSD Id: Makefile,v 1.10 1997/07/17 15:12:41 max Exp 
#

DISTNAME=       slang0.99-38
PKGNAME=        libslang-0.99.38
CATEGORIES=	devel
MASTER_SITES=   ftp://space.mit.edu/pub/davis/slang/

MAINTAINER=     packages@netbsd.org

GNU_CONFIGURE=  yes
ALL_TARGET=     all elf
INSTALL_TARGET= install install-elf
WRKSRC=         ${WRKDIR}/slang

post-install:
	@rm -f ${PREFIX}/lib/libslang.so.99.3[348]
	${LDCONFIG} || ${TRUE}

.include "../../mk/bsd.pkg.mk"
