# $NetBSD: Makefile,v 1.2 2003/07/03 15:32:35 seb Exp $
#

DISTNAME=		gnuplot-3.7.3
SVR4_PKGNAME=		gplot
PKGNAME=                ${DISTNAME:C/-/-nox11-/}
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gnuplot/} \
			ftp://ftp.ucc.ie/pub/gnuplot/ \
			ftp://ftp.cc.monash.edu.au/pub/gnuplot/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://sourceforge.net/projects/gnuplot/
COMMENT=		gnuplot is a nice plotting utility

CONFLICTS+=		gnuplot-[0-9]*

USE_BUILDLINK2=		YES
# because of missing rl_complete_with_tilde_expansion and rl_terminal_name
USE_GNU_READLINE=	YES
GNU_CONFIGURE=		YES

USE_NEW_TEXINFO=	YES
INFO_FILES=	gnuplot.info

CONFIGURE_ARGS+=	--with-pdf
CONFIGURE_ARGS+=	--with-plot=${LOCALBASE}
CONFIGURE_ARGS+=	--with-readline=${BUILDLINK_PREFIX.readline}
CONFIGURE_ARGS+=	--without-x

.include "../../devel/readline/buildlink2.mk"
.include "../../graphics/plotutils-nox11/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../print/pdflib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
