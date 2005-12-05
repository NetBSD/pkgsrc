# $NetBSD: Makefile,v 1.50 2005/12/05 20:50:01 rillig Exp $
#

DISTNAME=		GConf-1.0.9
PKGREVISION=		7
CATEGORIES=		devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/GConf/1.0/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://advogato.org/proj/GConf/
COMMENT=		Configuration database system used by GNOME

BUILD_DEPENDS+=		gtk-doc-[0-9]*:../../textproc/gtk-doc
BUILD_USES_MSGFMT=	yes

USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
MAKE_FLAGS+=		AM_MAKEFLAGS="BDBBACKEND="

USE_LIBTOOL=		YES
PKGCONFIG_OVERRIDE=	gconf.pc.in

PLIST_SUBST+=		LOCALBASE=${LOCALBASE:Q}

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
.include "../../devel/oaf/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
