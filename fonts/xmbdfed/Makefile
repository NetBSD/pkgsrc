# $NetBSD: Makefile,v 1.1.1.1 2002/10/15 12:29:19 kei Exp $

DISTNAME=	xmbdfed-4.4
CATEGORIES=	fonts graphics x11
MASTER_SITES=	ftp://crl.nmsu.edu/CLR/multiling/General/

MAINTAINER=	kei@netbsd.org
HOMEPAGE=	http://crl.nmsu.edu/~mleisher/xmbdfed.html
COMMENT=	Motif-based BDF font editor with lots of features

USE_BUILDLINK2=	YES
USE_X11BASE=	YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmbdfed ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xmbdfed.man ${PREFIX}/man/man1/xmbdfed.1

.include "../../graphics/freetype-lib/buildlink2.mk"
.include "../../mk/motif.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
