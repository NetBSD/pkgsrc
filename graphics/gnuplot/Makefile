# $NetBSD: Makefile,v 1.28 2004/06/25 17:08:13 adrianp Exp $
#

DISTNAME=		gnuplot-4.0.0
SVR4_PKGNAME=		gplot
CATEGORIES=		graphics x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gnuplot/} \
			ftp://ftp.ucc.ie/pub/gnuplot/ \
			ftp://ftp.cc.monash.edu.au/pub/gnuplot/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://gnuplot.sourceforge.net/
COMMENT=		Portable interactive, function plotting utility

CONFLICTS+=             gnuplot-nox11-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
# because of missing rl_complete_with_tilde_expansion and rl_terminal_name
USE_GNU_READLINE=	YES
USE_X11=		YES

USE_MAKEINFO=		YES
INFO_FILES=		gnuplot.info

CONFIGURE_ARGS+=	--with-pdf
CONFIGURE_ARGS+=	--with-plot=${LOCALBASE}
CONFIGURE_ARGS+=	--with-readline=${BUILDLINK_PREFIX.readline}

.include "../../devel/readline/buildlink3.mk"
.include "../../graphics/plotutils/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../print/pdflib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
