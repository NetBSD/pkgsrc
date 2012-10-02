# $NetBSD: Makefile,v 1.47 2012/10/02 17:10:38 tron Exp $
#

DISTNAME=	gwave2-20090213
PKGNAME=	${DISTNAME:S/gwave2/gwave/}
PKGREVISION=	6
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gwave/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://gwave.sourceforge.net
COMMENT=	Viewer for spice-like simulator output and other analog data
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=	YES
USE_LIBTOOL=	yes
USE_TOOLS+=	perl pkg-config

EVAL_PREFIX+=	GRAPHDIR=plotutils
CONFIGURE_ENV+=	GRAPH=${GRAPHDIR}/bin/graph

LDFLAGS.DragonFly=	-lX11

# make this file get rebuilt in a way that gcc3 can deal with
#post-extract:
#	${RM} ${WRKSRC}/src/init_scheme_string.c

.include "../../devel/guile-gnome/buildlink3.mk"
.include "../../graphics/plotutils/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
