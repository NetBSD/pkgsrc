# $NetBSD: Makefile,v 1.6 2001/11/13 03:16:50 damon Exp $

DISTNAME=	Guppi-0.40.0
CATEGORIES=	math graphics
MASTER_SITES=	${MASTER_SITE_GNOME:=stable/sources/Guppi/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.gnome.org/guppi/
COMMENT=	Plot program with integrated statistics capabilities

DEPENDS+=	gnome-core>=1.4:../../x11/gnome-core
DEPENDS+=	python>=2.0:../../lang/python

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_LIBTOOL=	YES
USE_X11BASE=	YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
PLIST_SUBST+=		LOCALBASE=${LOCALBASE}

post-install:
	${TEST} ${PREFIX} = ${LOCALBASE} || \
	${LN} -fs ${PREFIX}/share/aclocal/libguppi.m4 \
	  ${LOCALBASE}/share/aclocal/libguppi.m4

.include "../../devel/libglade/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
