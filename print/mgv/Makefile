# $NetBSD: Makefile,v 1.4 2001/09/12 04:56:06 jlam Exp $

DISTNAME=		mgv-3.1.5
CATEGORIES=		print
MASTER_SITES=		http://www.trends.net/~mu/srcs/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.trends.net/~mu/mgv.html
COMMENT=		Motif/LessTif user interface for Ghostscript

DEPENDS+=		ghostscript-[6-9]*:../../print/ghostscript

GNU_CONFIGURE=		yes
USE_BUILDLINK_ONLY=	yes

CONFIGURE_ARGS+=	--with-motif-includes=${BUILDLINK_DIR}/include
CONFIGURE_ARGS+=	--with-motif-libs=${BUILDLINK_DIR}/lib

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/*.gif ${PREFIX}/share/mgv/3.1.5/help
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html
	${LN} -fs ${PREFIX}/share/mgv/3.1.5/help ${PREFIX}/share/doc/html/mgv

.include "../../graphics/xpm/buildlink.mk"
.include "../../mk/motif.buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
