# $NetBSD: Makefile,v 1.1.1.1 2000/09/05 16:20:29 jwise Exp $
#

DISTNAME=	expect
PKGNAME=	tcl-expect-5.32.1
CATEGORIES=	lang
MASTER_SITES=	http://expect.nist.gov/

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://expect.nist.gov/

DEPENDS+=	tcl-8.3.2:../../lang/tcl

WRKSRC=		${WRKDIR}/expect-5.32
DIST_SUBDIR=	expect-5.32.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS= --enable-shared \
		--with-tclconfig=${PREFIX}/lib \
		--with-tclinclude=${PREFIX}/include/tcl \
		--without-x

.include "../../mk/bsd.prefs.mk"

#post-extract:
#	${MV} ${WRKSRC}/example/rftp ${WRKSRC}/example/expect-rftp

test:
	@(cd ${WRKSRC}; ${MAKE} test)

.include "../../mk/bsd.pkg.mk"
