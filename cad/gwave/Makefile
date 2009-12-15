# $NetBSD: Makefile,v 1.35 2009/12/15 21:31:52 joerg Exp $
#

DISTNAME=	gwave-20060606
PKGREVISION=	2
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.geda.seul.org/pub/geda/dist/ \
		http://www.geda.seul.org/dist/

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://www.cs.unc.edu/~tell/gwave.html
COMMENT=	Viewer for spice-like simulator output and other analog data

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=	YES
USE_LIBTOOL=	yes
USE_TOOLS+=	perl

EVAL_PREFIX+=	GRAPHDIR=plotutils
CONFIGURE_ENV+=	GRAPH=${GRAPHDIR}/bin/graph

# make this file get rebuilt in a way that gcc3 can deal with
post-extract:
	${RM} ${WRKSRC}/src/init_scheme_string.c

.include "../../devel/guile16-gtk/buildlink3.mk"
.include "../../graphics/plotutils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
