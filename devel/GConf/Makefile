# $NetBSD: Makefile,v 1.28 2002/07/18 02:19:36 rh Exp $
#

DISTNAME=		GConf-1.0.9
PKGREVISION=		1
CATEGORIES=		devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/GConf/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://advogato.org/proj/GConf/
COMMENT=		configuration database system used by GNOME

BUILD_USES_MSGFMT=	yes
#DEPENDS+=		guile>=1.3.4:../../lang/guile

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES
USE_X11BASE=		YES
USE_LIBTOOL=		YES

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
CPPFLAGS+=		-I${BUILDLINK_DIR}/include/db3
PLIST_SUBST+=		LOCALBASE=${LOCALBASE}

pre-build:
	${RM} -f ${WRKSRC}/gconf/libxml
	${LN} -sf ${BUILDLINK_DIR}/include/gnome-xml ${WRKSRC}/gconf/libxml

post-install:
	${TEST} ${PREFIX} = ${LOCALBASE} || \
	${LN} -fs ${PREFIX}/share/aclocal/gconf-1.m4 \
	    ${LOCALBASE}/share/aclocal/gconf-1.m4
	${TEST} -f ${PREFIX}/etc/gconf/1/path || \
	    ${CP} -p ${PREFIX}/etc/gconf/1/path.example \
	    ${PREFIX}/etc/gconf/1/path

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../databases/db3/buildlink.mk"
.include "../../devel/oaf/buildlink.mk"
.include "../../devel/popt/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
