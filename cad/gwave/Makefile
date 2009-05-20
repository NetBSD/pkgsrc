# $NetBSD: Makefile,v 1.33 2009/05/20 00:58:07 wiz Exp $
#

DISTNAME=	gwave-20060606
PKGREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.geda.seul.org/pub/geda/dist/ \
		http://www.geda.seul.org/dist/

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://www.cs.unc.edu/~tell/gwave.html
COMMENT=	Viewer for spice-like simulator output and other analog data

PKG_DESTDIR_SUPPORT=	user-destdir

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
