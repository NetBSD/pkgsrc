# $NetBSD: Makefile,v 1.18 2003/11/05 22:31:43 dmcmahill Exp $
#

DISTNAME=	gwave-20030804
CATEGORIES=	cad
MASTER_SITES=	http://www.cs.unc.edu/~tell/dist/

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://www.cs.unc.edu/~tell/gwave/
COMMENT=	Viewer for spice-like simulator output and other analog data

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

EVAL_PREFIX+=	GRAPHDIR=plotutils
CONFIGURE_ENV+=	GRAPH=${GRAPHDIR}/bin/graph

# make this file get rebuilt in a way that gcc3 can deal with
post-extract:
	${RM} ${WRKSRC}/src/init_scheme_string.c

.include "../../devel/guile-gtk/buildlink2.mk"
.include "../../graphics/plotutils/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
