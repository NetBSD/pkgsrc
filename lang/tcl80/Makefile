# $NetBSD: Makefile,v 1.16 1998/09/10 10:39:02 agc Exp $
# FreeBSD Id: Makefile,v 1.1.1.1 1997/08/20 10:33:35 jkh Exp
#

DISTNAME=		tcl8.0p2
PKGNAME=		tcl-8.0p2
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.scriptics.com/pub/tcl/tcl8_0/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.scriptics.com/

WRKSRC=			${WRKDIR}/tcl8.0/unix
GNU_CONFIGURE=		yes

# let libtool deal with shared libraries
USE_LIBTOOL=		yes
CONFIGURE_ARGS+=	--disable-shared

test:
	cd ${WRKSRC} && /usr/bin/env LIBTOOL=${LIBTOOL} PREFIX=${PREFIX} ${MAKE} test

.include "../../mk/bsd.pkg.mk"
