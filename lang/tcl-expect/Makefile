# $NetBSD: Makefile,v 1.8 2001/10/24 23:40:02 jwise Exp $
#

DISTNAME=	expect
PKGNAME=	tcl-expect-5.33
CATEGORIES=	lang
MASTER_SITES=	http://expect.nist.gov/

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://expect.nist.gov/
COMMENT=	extensions to Tcl to support scripting of interactive programs

DEPENDS+=	tcl>=8.3.2:../../lang/tcl

CONFLICTS+=	expect-[0-9]*

WRKSRC=		${WRKDIR}/expect-5.33
DIST_SUBDIR=	expect-5.33

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS= --enable-shared \
		--with-tclconfig=${PREFIX}/lib \
		--with-tclinclude=${PREFIX}/include/tcl \
		--without-x

.include "../../mk/bsd.prefs.mk"

pre-configure:
	cd ${WRKSRC} && ${TOUCH} configure

test:
	@(cd ${WRKSRC}; ${MAKE} test)

.include "../../mk/bsd.pkg.mk"
