# $NetBSD: Makefile,v 1.30 2002/01/28 05:18:41 jlam Exp $
# FreeBSD Id: Makefile,v 1.16 1997/07/13 18:49:29 max Exp
#

DISTNAME=	gv-3.5.8
CATEGORIES=	print
MASTER_SITES=	ftp://ftpthep.physik.uni-mainz.de/pub/gv/unix/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://wwwthep.physik.uni-mainz.de/~plass/gv/
COMMENT=	PostScript and PDF previewer

DEPENDS+=	ghostscript-[6-9]*:../../print/ghostscript

USE_IMAKE=	yes
XAW_TYPE?=	3d

.include "../../mk/bsd.prefs.mk"

# We need Xaw3d to build.
.if (${XAW_TYPE} == standard)
XAW_TYPE=	3d
.endif

post-extract:
	${MV} ${WRKSRC}/doc/gv.man ${WRKSRC}/source/

post-install:
	cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} install.doc

.include "../../mk/xaw.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
