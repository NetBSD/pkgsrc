# $NetBSD: Makefile,v 1.5 1998/04/22 14:22:41 agc Exp $
# FreeBSD Id: Makefile,v 1.12 1998/02/24 21:43:24 jseger Exp
#

DISTNAME=	tkcvs-6.0
CATEGORIES=	devel
MASTER_SITES=	http://www.neosoft.com/tcl/ftparchive/sorted/apps/tkcvs-6.0/ \
		http://ftp.sunet.se/pub/lang/tcl/sorted/apps/tkcvs-6.0/

MAINTAINER=	shanee@augusta.de

DEPENDS+=	tk-8.0p2:../../x11/tk80

NO_BUILD=	yes
MAN1=		tkcvs.1 tkdiff.1

post-extract:
	${CP} ${WRKSRC}/tkcvs/tkcvs.n ${WRKSRC}/tkcvs/tkcvs.1
	${CP} ${WRKSRC}/tkdiff/tkdiff.n ${WRKSRC}/tkdiff/tkdiff.1

do-install:
	(cd ${WRKSRC}/tkcvs; ${SETENV} ${MAKE_ENV} sh ./doinstall)

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/tkcvs
	${INSTALL_DATA} ${WRKSRC}/README.tkcvs ${PREFIX}/share/doc/tkcvs/
	${INSTALL_DATA} ${WRKSRC}/tkdiff/README ${PREFIX}/share/doc/tkcvs/README.tkdiff
.endif

.include "../../mk/bsd.pkg.mk"
