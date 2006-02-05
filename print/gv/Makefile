# $NetBSD: Makefile,v 1.58 2006/02/05 23:10:37 joerg Exp $

DISTNAME=	gv-3.6.1
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GNU:=gv/}

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gv/
COMMENT=	PostScript and PDF previewer

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake gs:run

USE_MAKEINFO=		yes
TEXINFO_REQD=		4.2
INFO_FILES=		gv.info

# this pkg does not work with std xaw, but xpm and xaw3d work
XAW_TYPE?=		3d
.include "../../mk/bsd.prefs.mk"
.if ${XAW_TYPE} == "standard"
XAW_TYPE=		3d
.endif

.if !exists(/usr/include/getopt.h)
.  include "../../pkgtools/libnbcompat/buildlink3.mk"
post-extract:
	cd ${WRKSRC}/src && ${LN} -s ${PREFIX}/include/nbcompat.h getopt.h

.endif

.include "../../mk/xaw.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
