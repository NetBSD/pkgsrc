# $NetBSD: Makefile,v 1.37 2003/06/02 01:17:29 jschauma Exp $
# FreeBSD Id: Makefile,v 1.16 1997/07/13 18:49:29 max Exp
#

DISTNAME=	gv-3.5.8
PKGREVISION=	3
CATEGORIES=	print
MASTER_SITES=	ftp://ftpthep.physik.uni-mainz.de/pub/gv/unix/

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://wwwthep.physik.uni-mainz.de/~plass/gv/
COMMENT=	PostScript and PDF previewer

USE_BUILDLINK2=		# defined
USE_IMAKE=		# defined
XAW_TYPE?=		3d

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
USE_GMAKE=		YES
.endif

# We need Xaw3d to build.
.if ${XAW_TYPE} == "standard"
XAW_TYPE:=	3d
.endif

post-extract:
	${MV} ${WRKSRC}/doc/gv.man ${WRKSRC}/source/

post-install:
	cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} install.doc

.include "../../mk/xaw.buildlink2.mk"
.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
