# $NetBSD: Makefile,v 1.44 2004/04/27 04:59:42 snj Exp $
#

DISTNAME=		GConf-1.0.9
PKGREVISION=		5
CATEGORIES=		devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/GConf/1.0/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://advogato.org/proj/GConf/
COMMENT=		Configuration database system used by GNOME

BUILD_USES_MSGFMT=	yes
#DEPENDS+=		guile>=1.3.4:../../lang/guile

USE_BUILDLINK3=		YES
USE_PKGLOCALEDIR=	YES
USE_X11BASE=		YES
GNU_CONFIGURE=		YES

USE_LIBTOOL=		YES
PKGCONFIG_OVERRIDE=	gconf.pc.in

CPPFLAGS+=		-I${BUILDLINK_PREFIX.db3}/include/db3
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

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../databases/db3/buildlink3.mk"
.include "../../devel/oaf/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
