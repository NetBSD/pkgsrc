# $NetBSD: Makefile,v 1.21 2000/09/03 15:04:20 wiz Exp $
# FreeBSD Id: Makefile,v 1.29 1998/01/27 01:11:47 fenner Exp
#

DISTNAME=	expect
PKGNAME=	expect-5.25
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_BACKUP}

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://expect.nist.gov/

DEPENDS+=	tk-8.3.2:../../x11/tk

BROKEN=		This package has not yet been updated to work with tcl-8.3.2.

WRKSRC=		${WRKDIR}/expect-5.25

GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --enable-shared \
		--with-tclconfig=${PREFIX}/lib/tcl8.0 \
		--with-tclinclude=${PREFIX}/include/tcl8.0 \
		--with-tkconfig=${PREFIX}/lib/tk8.0 \
		--with-tkinclude=${PREFIX}/include/tk8.0

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
LD_LIBRARY_PATH?=	/usr/lib:${LOCALBASE}/lib:${X11BASE}/lib
MAKE_ENV+=		LD_LIBRARY_PATH=${LD_LIBRARY_PATH}
.endif

post-extract:
	${MV} ${WRKSRC}/example/rftp ${WRKSRC}/example/expect-rftp

test:
	@(cd ${WRKSRC}; ${MAKE} test)

.include "../../mk/bsd.pkg.mk"
