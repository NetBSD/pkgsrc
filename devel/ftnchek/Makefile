# $NetBSD: Makefile,v 1.3 2001/02/16 14:38:24 wiz Exp $
#

DISTNAME=		ftnchek
PKGNAME=		ftnchek-3.0.0
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.netlib.org/fortran/ \
			ftp://netlib.bell-labs.com/netlib/fortran/ \
			ftp://www.hensa.ac.uk/mirrors/netlib/fortran/
EXTRACT_SUFX=		.tgz

MAINTAINER=		jasontd@indigo.ie
HOMEPAGE=		http://www.dsm.fordham.edu/~ftnchek
COMMENT=		Static analyzer for Fortran programs

WRKSRC=			${WRKDIR}/${PKGNAME}
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--libdir=${PREFIX}/libexec

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ftnchek
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ftnchek/html
	@for i in FAQ INSTALL LICENSE README ftnchek.man dcl2inc.man \
	macro-doc.txt; do \
	${INSTALL_DATA} ${WRKSRC}/$$i ${PREFIX}/share/doc/ftnchek; done
	${INSTALL_DATA} ${WRKSRC}/html/* ${PREFIX}/share/doc/ftnchek/html

.include "../../mk/bsd.pkg.mk"
