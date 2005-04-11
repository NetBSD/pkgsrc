# $NetBSD: Makefile,v 1.15 2005/04/11 21:47:08 tv Exp $

DISTNAME=		mgv-3.1.5
PKGREVISION=		2
CATEGORIES=		print
MASTER_SITES=		http://www.trends.net/~mu/srcs/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.trends.net/~mu/mgv.html
COMMENT=		Motif/LessTif user interface for Ghostscript

GNU_CONFIGURE=		yes
USE_X11BASE=		yes

CONFIGURE_ARGS+=	--with-motif-includes=${MOTIFBASE}/include
CONFIGURE_ARGS+=	--with-motif-libs=${MOTIFBASE}/lib

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/*.gif ${PREFIX}/share/mgv/3.1.5/help
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html
	${LN} -fs ${PREFIX}/share/mgv/3.1.5/help ${PREFIX}/share/doc/html/mgv

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"

.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
