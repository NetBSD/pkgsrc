# $NetBSD: Makefile,v 1.22 2009/06/30 00:07:22 joerg Exp $

DISTNAME=		mgv-3.1.5
PKGREVISION=		4
CATEGORIES=		print
MASTER_SITES=		#

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://web.archive.org/web/20020201231345/http://www.trends.net/~mu/mgv.html
COMMENT=		Motif/LessTif user interface for Ghostscript

MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=		yes
USE_X11BASE=		yes
USE_TOOLS+=		gs:run

CONFIGURE_ARGS+=	--with-motif-includes=${MOTIFBASE}/include
CONFIGURE_ARGS+=	--with-motif-libs=${MOTIFBASE}/lib

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/*.gif ${PREFIX}/share/mgv/3.1.5/help
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html
	${LN} -fs ${PREFIX}/share/mgv/3.1.5/help ${PREFIX}/share/doc/html/mgv

.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
