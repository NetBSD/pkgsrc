# $NetBSD: Makefile,v 1.15 2001/06/11 06:34:25 jlam Exp $
#

DISTNAME=	GConf-1.0.0
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=unstable/sources/GConf/}

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
CPPFLAGS+=	-I${X11PREFIX}/include
PLIST_SUBST+=	LOCALBASE=${LOCALBASE}

post-install:
	${TEST} ${PREFIX} = ${LOCALBASE} || \
	${LN} -fs ${PREFIX}/share/aclocal/gconf-1.m4 \
	  ${LOCALBASE}/share/aclocal/gconf-1.m4

.include "../../mk/bsd.pkg.mk"
