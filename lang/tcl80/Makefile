# $NetBSD: Makefile,v 1.25 2000/06/01 11:23:34 rh Exp $
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
USE_PKGLIBTOOL=		yes
CONFIGURE_ARGS+=	--disable-shared

# manual pages go into tclman80
INSTALL_TARGET=		install-binaries install-libraries

test:
	cd ${WRKSRC} && ${SETENV} LIBTOOL=${LIBTOOL} PREFIX=${PREFIX} ${MAKE} test

.include "../../mk/bsd.pkg.mk"
