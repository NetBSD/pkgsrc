# $NetBSD: Makefile,v 1.43 2004/10/03 00:18:05 tv Exp $
# FreeBSD Id: Makefile,v 1.16 1997/07/13 18:49:29 max Exp
#

DISTNAME=	gv-3.5.8
PKGREVISION=	4
CATEGORIES=	print
MASTER_SITES=	ftp://ftpthep.physik.uni-mainz.de/pub/gv/unix/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://wwwthep.physik.uni-mainz.de/~plass/gv/
COMMENT=	PostScript and PDF previewer

USE_BUILDLINK3=		# defined
USE_IMAKE=		# defined
XAW_TYPE?=		3d

IMAKEOPTS+=		-DCONVERT_INCLUDE_DIRECTIVES

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
USE_GNU_TOOLS+=		make
.elif ${OPSYS} == "IRIX" && !empty(ABI)
# Hack to put the correct path first -- otherwise, buildlink will first try to link X11BASE/lib
.  if ${ABI} == "64"
IMAKEOPTS+=		-DsgiABIopts="-L/usr/lib${ABI} -DLONG64"
.  else
IMAKEOPTS+=		-DsgiABIdefs=-L/usr/lib${ABI}
.  endif
.endif

# We need Xaw3d to build.
.if ${XAW_TYPE} == "standard"
XAW_TYPE:=	3d
.endif

post-extract:
	${MV} ${WRKSRC}/doc/gv.man ${WRKSRC}/source/

post-install:
	cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} install.doc

.include "../../mk/xaw.buildlink3.mk"
.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
