# $NetBSD: Makefile,v 1.5 2004/04/17 01:14:19 snj Exp $
#

DISTNAME=		gnuplot-3.7.3
PKGNAME=                ${DISTNAME:C/-/-nox11-/}
SVR4_PKGNAME=		gplot
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gnuplot/} \
			ftp://ftp.ucc.ie/pub/gnuplot/ \
			ftp://ftp.cc.monash.edu.au/pub/gnuplot/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://sourceforge.net/projects/gnuplot/
COMMENT=		Gnuplot is a nice plotting utility

CONFLICTS+=		gnuplot-[0-9]*

USE_BUILDLINK3=		YES
# because of missing rl_complete_with_tilde_expansion and rl_terminal_name
USE_GNU_READLINE=	YES
GNU_CONFIGURE=		YES

INFO_FILES=	gnuplot.info

CONFIGURE_ARGS+=	--with-pdf
CONFIGURE_ARGS+=	--with-plot=${LOCALBASE}
CONFIGURE_ARGS+=	--with-readline=${BUILDLINK_PREFIX.readline}
CONFIGURE_ARGS+=	--without-x

.include "../../devel/readline/buildlink3.mk"
.include "../../graphics/plotutils-nox11/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../print/pdflib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
