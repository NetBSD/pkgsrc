# $NetBSD: Makefile,v 1.23 1999/04/08 17:32:27 tron Exp $
# FreeBSD Id: Makefile,v 1.1.1.1 1997/08/20 10:33:35 jkh Exp
#

DISTNAME=		tcl8.0.5
PKGNAME=		tcl-8.0.5
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.scriptics.com/pub/tcl/tcl8_0/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.scriptics.com/

WRKSRC=			${WRKDIR}/${DISTNAME}/unix
GNU_CONFIGURE=		yes

# Use disable-shared, so that libtool works with the generated Makefile
USE_LIBTOOL=		yes
CONFIGURE_ARGS+=	--disable-shared

post-patch:
	cd ${WRKSRC}/../doc; \
		${MV} Object.3 Tcl_Obj.3

test:
	cd ${WRKSRC} && ${SETENV} LIBTOOL=${LIBTOOL} PREFIX=${PREFIX} ${MAKE} test

.include "../../mk/bsd.pkg.mk"
