# $NetBSD: Makefile,v 1.8 2005/06/16 06:57:52 jlam Exp $

DISTNAME=	xmbdfed-4.5
PKGREVISION=	#
CATEGORIES=	fonts graphics x11
MASTER_SITES=	ftp://crl.nmsu.edu/CLR/multiling/General/

MAINTAINER=	kei@NetBSD.org
HOMEPAGE=	http://crl.nmsu.edu/~mleisher/xmbdfed.html
COMMENT=	Motif-based BDF font editor with lots of features

USE_X11BASE=	YES

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmbdfed ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xmbdfed.man ${PREFIX}/man/man1/xmbdfed.1

.include "../../graphics/freetype-lib/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
