# $NetBSD: Makefile,v 1.24 2003/07/21 16:51:43 martti Exp $
#

DISTNAME=		gnuplot-3.7.3
SVR4_PKGNAME=		gplot
PKGREVISION=		1
CATEGORIES=		graphics x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gnuplot/} \
			ftp://ftp.ucc.ie/pub/gnuplot/ \
			ftp://ftp.cc.monash.edu.au/pub/gnuplot/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://sourceforge.net/projects/gnuplot/
COMMENT=		Gnuplot is a nice plotting utility

CONFLICTS+=             gnuplot-nox11-[0-9]*

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
# because of missing rl_complete_with_tilde_expansion and rl_terminal_name
USE_GNU_READLINE=	YES
USE_X11=		YES

USE_NEW_TEXINFO=	YES
INFO_FILES=	gnuplot.info

CONFIGURE_ARGS+=	--with-pdf
CONFIGURE_ARGS+=	--with-plot=${LOCALBASE}
CONFIGURE_ARGS+=	--with-readline=${BUILDLINK_PREFIX.readline}

.include "../../devel/readline/buildlink2.mk"
.include "../../graphics/plotutils/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../print/pdflib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
