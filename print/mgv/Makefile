# $NetBSD: Makefile,v 1.9 2002/08/25 21:50:32 jlam Exp $

DISTNAME=		mgv-3.1.5
PKGREVISION=		1
CATEGORIES=		print
MASTER_SITES=		http://www.trends.net/~mu/srcs/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.trends.net/~mu/mgv.html
COMMENT=		Motif/LessTif user interface for Ghostscript

DEPENDS+=		ghostscript-[6-9]*:../../print/ghostscript

GNU_CONFIGURE=		yes
USE_X11BASE=		yes
USE_BUILDLINK2=		yes

CONFIGURE_ARGS+=	--with-motif-includes=${MOTIFBASE}/include
CONFIGURE_ARGS+=	--with-motif-libs=${MOTIFBASE}/lib

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/*.gif ${PREFIX}/share/mgv/3.1.5/help
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html
	${LN} -fs ${PREFIX}/share/mgv/3.1.5/help ${PREFIX}/share/doc/html/mgv

.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/motif.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
