# $NetBSD: Makefile,v 1.25 2000/05/07 02:11:18 jlam Exp $
# FreeBSD Id: Makefile,v 1.16 1997/07/13 18:49:29 max Exp
#

DISTNAME=	gv-3.5.8
CATEGORIES=	print
MASTER_SITES=	ftp://ftpthep.physik.uni-mainz.de/pub/gv/unix/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://wwwthep.physik.uni-mainz.de/~plass/gv/

DEPENDS+=	ghostscript-x11-*:../../print/ghostscript-x11

USE_IMAKE=	yes
USE_XAW=	yes

.include "../../mk/bsd.prefs.mk"

XAW_TYPE?=	3d
.if (${XAW_TYPE} == standard)
DEPENDS+=	Xaw3d-1.5:../../x11/Xaw3d
.endif

post-extract:
	${MV} ${WRKSRC}/doc/gv.man ${WRKSRC}/source/

post-install:
	@(cd ${WRKSRC}; ${MAKE} install.doc)

.include "../../mk/bsd.pkg.mk"
