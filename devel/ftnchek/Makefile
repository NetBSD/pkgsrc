# $NetBSD: Makefile,v 1.1.1.1 2000/11/06 18:11:39 wennmach Exp $
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

WRKSRC=			${WRKDIR}/${PKGNAME}
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--libdir=${PREFIX}/libexec

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ftnchek
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ftnchek/html
	@(cd ${WRKSRC};							\
	for i in FAQ INSTALL LICENSE README ftnchek.man dcl2inc.man 	\
	macro-doc.txt; do						\
	${INSTALL_DATA} $$i ${PREFIX}/share/doc/ftnchek;		\
	done;								\
	cd html;							\
	for j in *.html; do						\
	${INSTALL_DATA} $$j ${PREFIX}/share/doc/ftnchek/html;		\
	done;)

.include "../../mk/bsd.pkg.mk"
