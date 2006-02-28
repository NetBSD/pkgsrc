# $NetBSD: Makefile,v 1.52 2006/02/28 17:41:02 wiz Exp $
#

DISTNAME=		GConf-1.0.9
PKGREVISION=		9
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

REQD_DIRS+=		${PKG_SYSCONFDIR}/gconf ${PKG_SYSCONFDIR}/gconf/1
CONF_FILES+=		${PREFIX}/share/examples/gconf/default.path \
			${PKG_SYSCONFDIR}/gconf/1/path

pre-build:
	${RM} -f ${WRKSRC}/gconf/libxml
	${LN} -sf ${BUILDLINK_DIR}/include/gnome-xml ${WRKSRC}/gconf/libxml

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/oaf/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
