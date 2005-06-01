# $NetBSD: Makefile,v 1.54 2005/06/01 18:03:09 jlam Exp $

DISTNAME=	gv-3.6.1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GNU:=gv/}

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gv/
COMMENT=	PostScript and PDF previewer

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

USE_MAKEINFO=		yes
TEXINFO_REQD=		4.2
INFO_FILES=		gv.info

XAW_TYPE=		3d

.if !exists(/usr/include/getopt.h)
.  include "../../pkgtools/libnbcompat/buildlink3.mk"
post-extract:
	cd ${WRKSRC}/src && ${LN} -s ${PREFIX}/include/nbcompat.h getopt.h

.endif

.include "../../mk/xaw.buildlink3.mk"
.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
