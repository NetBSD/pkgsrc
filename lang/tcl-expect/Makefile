# $NetBSD: Makefile,v 1.11 2003/01/10 00:11:00 mycroft Exp $
#

DISTNAME=	expect-5.38.0
PKGNAME=	tcl-expect-5.38.0
CATEGORIES=	lang
MASTER_SITES=	http://expect.nist.gov/src/

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://expect.nist.gov/
COMMENT=	extensions to Tcl to support scripting of interactive programs

DEPENDS+=	tcl>=8.3.2:../../lang/tcl

WRKSRC=		${WRKDIR}/expect-5.38
CONFLICTS+=	expect-[0-9]*

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS= --enable-shared \
		--with-tclconfig=${PREFIX}/lib \
		--with-tclinclude=${PREFIX}/include/tcl \
		--without-x

test:
	@(cd ${WRKSRC}; ${MAKE} test)

.include "../../mk/bsd.pkg.mk"
