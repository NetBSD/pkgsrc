# $NetBSD: Makefile,v 1.13 1998/07/04 04:11:34 mycroft Exp $
# FreeBSD Id: Makefile,v 1.1.1.1 1997/08/20 10:33:35 jkh Exp
#

DISTNAME=		tcl8.0p2
PKGNAME=		tcl-8.0p2
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.scriptics.com/pub/tcl/tcl8_0/

MAINTAINER=		packages@netbsd.org

WRKSRC=			${WRKDIR}/tcl8.0/unix
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ENV+=		PORTSDIR=${.CURDIR}/../../../../..

post-install:
	${LDCONFIG} || ${TRUE}

test:
	cd ${WRKSRC} && ${MAKE} test

.include "../../mk/bsd.pkg.mk"
