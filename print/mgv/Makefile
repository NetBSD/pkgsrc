# $NetBSD: Makefile,v 1.1.1.1 2001/04/14 00:51:16 jtb Exp $

DISTNAME=		mgv-3.1.5
CATEGORIES=		print
MASTER_SITES=		http://www.trends.net/~mu/srcs/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.trends.net/~mu/mgv.html
COMMENT=		Motif/LessTif user interface for Ghostscript

GNU_CONFIGURE=		yes
USE_X11=		yes
USE_MOTIF=		yes
USE_XPM=		yes

CONFIGURE_ARGS+=	--with-motif-includes=${MOTIFBASE}/include
CONFIGURE_ARGS+=	--with-motif-libs=${MOTIFBASE}/lib

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html
	${LN} -fs ${PREFIX}/share/mgv/3.1.5/help ${PREFIX}/share/doc/html/mgv

.include "../../mk/bsd.pkg.mk"
