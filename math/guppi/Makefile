# $NetBSD: Makefile,v 1.22 2002/12/01 15:56:56 salo Exp $

DISTNAME=	Guppi-0.40.3
PKGNAME=	${DISTNAME:S/G/g/}
PKGREVISION=	1
CATEGORIES=	math graphics
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/Guppi/0.40/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnome.org/guppi/
COMMENT=	Plot program with integrated statistics capabilities

.if exists(/usr/include/wctype.h)
#
# "guppi" only accepts newer versions of the "gnumeric" package which
# cannot be build on all platforms. We only enable "gnumeric" support
# on platforms which can build the "gnumeric" 1.0.x packages.
#
DEPENDS+=		gnumeric>=1.0.9:../../math/gnumeric
CONFIGURE_ARGS=		--enable-gnumeric
PLIST_SUBST+=		GNUMERIC=
.else
CONFIGURE_ARGS=		--disable-gnumeric
PLIST_SUBST+=		GNUMERIC="@comment "
.endif
DEPENDS+=		guile>=1.4:../../lang/guile

USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_X11BASE=		YES
USE_GMAKE=		YES
GNU_CONFIGURE=		YES

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PLIST_SUBST+=		LOCALBASE=${LOCALBASE}

post-install:
	${TEST} ${PREFIX} = ${LOCALBASE} || \
	${LN} -fs ${PREFIX}/share/aclocal/libguppi.m4 \
		${LOCALBASE}/share/aclocal/libguppi.m4

.include "../../devel/libglade/buildlink2.mk"
.include "../../devel/readline/buildlink2.mk"
.include "../../x11/gnome-core/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
