# $NetBSD: Makefile,v 1.8 2000/11/27 16:00:19 tron Exp $
#

DISTNAME=	GConf-0.11
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=unstable/sources/GConf/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://advogato.org/proj/GConf/

DEPENDS+=	gnome-core>=1.2.0:../../x11/gnome-core
DEPENDS+=	oaf-*:../../devel/oaf
DEPENDS+=	guile>=1.3.4:../../lang/guile
BUILD_DEPENDS+=	msgfmt:../../devel/gettext

MESSAGE_FILE=	${WRKDIR}/MESSAGE

GNU_CONFIGURE=	YES
USE_X11BASE=	YES
USE_LIBINTL=	YES
USE_LIBTOOL=	YES

LTCONFIG_OVERRIDE=${WRKSRC}/ltconfig
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS} -I${X11PREFIX}/include"
PLIST_SUBST+=	LOCALBASE=${LOCALBASE}

post-install:
	${SED} -e 's#@@X11PREFIX@@#${X11PREFIX}#g' < ${PKGDIR}/MESSAGE \
		> ${MESSAGE_FILE}
	${TEST} ${PREFIX} = ${LOCALBASE} || \
	${LN} -fs ${PREFIX}/share/aclocal/gconf-1.m4 \
	  ${LOCALBASE}/share/aclocal/gconf-1.m4

.include "../../mk/bsd.pkg.mk"
