# $NetBSD: Makefile,v 1.85 2022/08/11 05:08:02 gutteridge Exp $
#

DISTNAME=	jack-rack-1.4.7
PKGREVISION=	76
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=jack-rack/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jack-rack.sourceforge.net/
COMMENT=	Effects "rack" for JACK
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		autoconf gmake msgfmt pkg-config

CONFIGURE_ARGS+=	--disable-aseq
CONFIGURE_ARGS+=	--disable-lash

BUILD_DEFS+=		LADSPA_PLUGIN_PATH
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
LDFLAGS.DragonFly=	-lm
LDFLAGS.SunOS+=		-lm
CFLAGS.SunOS+=		-std=c99 -D_XOPEN_SOURCE=600 -D__EXTENSIONS__

###
### NOTE: this is a colon-delimited list like e.g. PATH.
###
LADSPA_PLUGIN_PATH?=		${PREFIX}/lib/ladspa

###
### XXX This package will not find the headers it wants otherwise.
###
CPPFLAGS+=	-I${BUILDLINK_PREFIX.glib2}/include/glib
CPPFLAGS+=	-DLADSPA_PATH="\"${LADSPA_PLUGIN_PATH}\""

pre-configure:
	cd ${WRKSRC} && autoconf

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/ecarack ${DESTDIR}${EGDIR}/ecarack.py

.include "../../textproc/xmlcatmgr/catalogs.mk"

.include "../../audio/jack/buildlink3.mk"
.include "../../audio/ladspa/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/liblrdf/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
