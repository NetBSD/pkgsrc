# $NetBSD: Makefile,v 1.14 2000/03/16 12:31:02 wiz Exp $
# FreeBSD Id: Makefile,v 1.12 1998/02/24 21:43:24 jseger Exp
#

DISTNAME=	tkcvs-6.0
CATEGORIES=	devel
MASTER_SITES=	http://www.neosoft.com/tcl/ftparchive/sorted/apps/tkcvs-6.0/ \
		http://ftp0.sunet.se/pub/lang/tcl/sorted/apps/tkcvs-6.0/

MAINTAINER=	shanee@augusta.de

DEPENDS+=	tk-8.0.5:../../x11/tk80

NO_BUILD=	yes

post-extract:
	${CP} ${WRKSRC}/tkcvs/tkcvs.n ${WRKSRC}/tkcvs/tkcvs.1
	${CP} ${WRKSRC}/tkdiff/tkdiff.n ${WRKSRC}/tkdiff/tkdiff.1

do-install:
	(cd ${WRKSRC}/tkcvs; ${SETENV} ${MAKE_ENV} ${SH} ./doinstall)

post-install:
	${MKDIR} ${PREFIX}/share/doc/tkcvs
	${INSTALL_DATA} ${WRKSRC}/README.tkcvs ${PREFIX}/share/doc/tkcvs/
	${INSTALL_DATA} ${WRKSRC}/tkdiff/README ${PREFIX}/share/doc/tkcvs/README.tkdiff

.include "../../mk/bsd.pkg.mk"
