# $NetBSD: Makefile,v 1.9 2001/10/24 23:40:03 jwise Exp $
#

DISTNAME=	expect
PKGNAME=	tk-expect-5.33
CATEGORIES=	lang
MASTER_SITES=	http://expect.nist.gov/

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://expect.nist.gov/
COMMENT=	tcl interpreter with both the expect and tk extensions built in

DEPENDS+=	tk>=8.3.2:../../x11/tk
DEPENDS+=	tcl-expect-5.33:../../lang/tcl-expect

WRKSRC=		${WRKDIR}/expect-5.33
DIST_SUBDIR=	expect-5.33

DISTINFO_FILE=	${.CURDIR}/../../lang/tcl-expect/distinfo
PATCHDIR=	${.CURDIR}/../../lang/tcl-expect/patches

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS= --enable-shared \
		--with-tclconfig=${PREFIX}/lib \
		--with-tkconfig=${PREFIX}/lib \
		--with-tclinclude=${PREFIX}/include/tcl \
		--with-tkinclude=${PREFIX}/include/tk \

.include "../../mk/bsd.prefs.mk"

pre-configure:
	cd ${WRKSRC} && ${TOUCH} configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/expectk ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/expectk.man ${PREFIX}/man/man1/expectk.1

test:
	@(cd ${WRKSRC}; ${MAKE} test)

.include "../../mk/bsd.pkg.mk"
