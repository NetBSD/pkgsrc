# $NetBSD: Makefile,v 1.17 2001/08/26 16:55:46 rh Exp $
#

DISTNAME=	GConf-1.0.4
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=unstable/sources/GConf/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://advogato.org/proj/GConf/
COMMENT=	configuration database system used by GNOME

BUILD_USES_MSGFMT=	yes
DEPENDS+=	oaf>=0.6.5:../../devel/oaf
DEPENDS+=	guile>=1.3.4:../../lang/guile

GNU_CONFIGURE=	YES
USE_X11BASE=	YES
USE_LIBINTL=	YES
USE_LIBTOOL=	YES

LTCONFIG_OVERRIDE=${WRKSRC}/ltconfig
CPPFLAGS+=	-I${LOCALBASE}/include/db3 -I${X11PREFIX}/include
PLIST_SUBST+=	LOCALBASE=${LOCALBASE}

post-install:
	${TEST} ${PREFIX} = ${LOCALBASE} || \
	${LN} -fs ${PREFIX}/share/aclocal/gconf-1.m4 \
	  ${LOCALBASE}/share/aclocal/gconf-1.m4

.include "../../databases/db3/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
