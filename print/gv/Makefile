# $NetBSD: Makefile,v 1.16 1998/12/23 23:09:59 frueauf Exp $
# FreeBSD Id: Makefile,v 1.16 1997/07/13 18:49:29 max Exp
#

DISTNAME=	gv-3.5.8
CATEGORIES=	print
MASTER_SITES=	ftp://ftpthep.physik.uni-mainz.de/pub/gv/unix/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://wwwthep.physik.uni-mainz.de/~plass/gv/

DEPENDS+=	Xaw3d-1.5:../../x11/Xaw3d
DEPENDS+=	ghostscript-5.50:../../print/ghostscript5

USE_IMAKE=	yes

.include "../../mk/bsd.prefs.mk"

post-extract:
	${MV} ${WRKSRC}/doc/gv.man ${WRKSRC}/source/

post-install:
.if !defined(NOPORTDOCS)
	@(cd ${WRKSRC}; ${MAKE} install.doc)
.endif
	@${SH} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
