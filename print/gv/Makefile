# $NetBSD: Makefile,v 1.10 1998/04/24 09:20:37 agc Exp $
# FreeBSD Id: Makefile,v 1.16 1997/07/13 18:49:29 max Exp
#

DISTNAME=	gv-3.5.8
CATEGORIES=	print
MASTER_SITES=	ftp://ftpthep.physik.uni-mainz.de/pub/gv/unix/

MAINTAINER=	packages@netbsd.org

DEPENDS+=	Xaw3d-1.3:../../x11/Xaw3d
RUN_DEPENDS=	${LOCALBASE}/bin/gs:../../print/ghostscript5

USE_IMAKE=	yes

CAT1=		gv.0

post-install:
.if !defined(NOPORTDOCS)
	@(cd ${WRKSRC}; ${MAKE} install.doc)
.endif
	@${SH} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
