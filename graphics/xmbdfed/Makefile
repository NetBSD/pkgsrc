# $NetBSD: Makefile,v 1.1.1.1 2002/03/19 16:17:11 kei Exp $

DISTNAME=	xmbdfed-4.4
CATEGORIES=	graphics x11
MASTER_SITES=	ftp://crl.nmsu.edu/CLR/multiling/General/

MAINTAINER=	kei@netbsd.org
HOMEPAGE=	http://crl.nmsu.edu/~mleisher/xmbdfed.html
COMMENT=	Motif-based BDF font editor with lots of features

USE_BUILDLINK_X11= yes
NO_CONFIGURE=	# defined

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmbdfed ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xmbdfed.man ${PREFIX}/man/man1/xmbdfed.1

.include "../../graphics/freetype-lib/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/motif.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
