# $NetBSD: Makefile,v 1.13 1998/06/22 12:44:30 agc Exp $
# FreeBSD Id: Makefile,v 1.29 1998/01/27 01:11:47 fenner Exp
#

DISTNAME=	expect
PKGNAME=	expect-5.25
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_BACKUP}

MAINTAINER=	packages@netbsd.org

DEPENDS+=	tk-8.0p2:../../x11/tk80

WRKSRC=		${WRKDIR}/expect-5.25

GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --enable-shared \
		--with-tclconfig=${PREFIX}/lib/tcl8.0 \
		--with-tclinclude=${PREFIX}/include/tcl8.0 \
		--with-tkconfig=${PREFIX}/lib/tk8.0 \
		--with-tkinclude=${PREFIX}/include/tk8.0

post-extract:
	${MV} ${WRKSRC}/example/rftp ${WRKSRC}/example/expect-rftp

test:
	@(cd ${WRKSRC}; make test)

post-install:
	${LDCONFIG} || ${TRUE}

.include "../../mk/bsd.pkg.mk"
