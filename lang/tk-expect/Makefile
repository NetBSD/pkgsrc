# $NetBSD: Makefile,v 1.1.1.1 2000/09/05 17:13:30 jwise Exp $
#

DISTNAME=	expect
PKGNAME=	tk-expect-5.32.1
CATEGORIES=	lang
MASTER_SITES=	http://expect.nist.gov/

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://expect.nist.gov/

DEPENDS+=	tcl-8.3.2:../../lang/tcl

WRKSRC=		${WRKDIR}/expect-5.32
DIST_SUBDIR=	expect-5.32.1

FILESDIR=	${.CURDIR}/../../lang/tcl-expect/files
PATCHDIR=	${.CURDIR}/../../lang/tcl-expect/patches

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS= --enable-shared \
		--with-tclconfig=${PREFIX}/lib \
		--with-tkconfig=${PREFIX}/lib \
		--with-tclinclude=${PREFIX}/include/tcl \
		--with-tkinclude=${PREFIX}/include/tk \

.include "../../mk/bsd.prefs.mk"

do-install:
	${INSTALL_BIN} ${WRKSRC}/expectk ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/expectk.man ${PREFIX}/man/man1/expectk.1

test:
	@(cd ${WRKSRC}; ${MAKE} test)

.include "../../mk/bsd.pkg.mk"
