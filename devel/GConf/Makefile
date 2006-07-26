# $NetBSD: Makefile,v 1.57 2006/07/26 12:50:26 drochner Exp $
#

DISTNAME=		GConf-1.0.9
PKGREVISION=		11
CATEGORIES=		devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/GConf/1.0/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://advogato.org/proj/GConf/
COMMENT=		Configuration database system used by GNOME

USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		msgfmt
GNU_CONFIGURE=		YES
MAKE_FLAGS+=		AM_MAKEFLAGS="BDBBACKEND="

USE_LIBTOOL=		YES
PKGCONFIG_OVERRIDE=	gconf.pc.in

PLIST_SUBST+=		LOCALBASE=${LOCALBASE:Q}

EGDIR=			${PREFIX}/share/examples/gconf
REQD_DIRS+=		${PKG_SYSCONFDIR}/gconf ${PKG_SYSCONFDIR}/gconf/1
REQD_DIRS+=		${PKG_SYSCONFDIR}/gconf/schemas
CONF_FILES+=		${EGDIR}/default.path ${PKG_SYSCONFDIR}/gconf/1/path
CONF_FILES+=		${EGDIR}/desktop.schemas \
			${PKG_SYSCONFDIR}/gconf/schemas/desktop.schemas

INSTALL_MAKE_FLAGS+=	schemadir=${EGDIR}

pre-build:
	${RM} -f ${WRKSRC}/gconf/libxml
	${LN} -sf ${BUILDLINK_DIR}/include/gnome-xml ${WRKSRC}/gconf/libxml

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/oaf/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
