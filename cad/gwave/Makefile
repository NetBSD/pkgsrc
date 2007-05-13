# $NetBSD: Makefile,v 1.29 2007/05/13 11:58:48 dmcmahill Exp $
#

DISTNAME=	gwave-20030804
PKGREVISION=	5
CATEGORIES=	cad
MASTER_SITES=	http://www.cs.unc.edu/~tell/dist/

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://www.cs.unc.edu/~tell/gwave.html
COMMENT=	Viewer for spice-like simulator output and other analog data

GNU_CONFIGURE=	YES
USE_LIBTOOL=	yes
USE_TOOLS+=	perl

EVAL_PREFIX+=	GRAPHDIR=plotutils
CONFIGURE_ENV+=	GRAPH=${GRAPHDIR}/bin/graph

# make this file get rebuilt in a way that gcc3 can deal with
post-extract:
	${RM} ${WRKSRC}/src/init_scheme_string.c

.include "../../devel/guile-gtk/buildlink3.mk"
.include "../../graphics/plotutils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
