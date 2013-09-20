# $NetBSD: Makefile,v 1.28 2013/09/20 11:51:43 obache Exp $
#

DISTNAME=	ibus-chewing-1.4.3-Source
PKGNAME=	${DISTNAME:S/-Source//}
PKGREVISION=	5
CATEGORIES=	inputmethod chinese
MASTER_SITES=	http://ibus.googlecode.com/files/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://code.google.com/p/ibus/
COMMENT=	Chewing engine for IBus input platform
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=		gob2-[0-9]*:../../devel/gob2

USE_CMAKE=		yes
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgmerge pkg-config

SUBST_CLASSES+=		msgctxt
SUBST_STAGE.msgctxt=	post-patch
SUBST_FILES.msgctxt=	po/*.po po/*.pot
SUBST_FILTER_CMD.msgctxt=	${STRIP_CMD.${MSGFMT_STRIP_MSGCTXT}}
STRIP_CMD.yes=	${AWK} -f ${PKGSRCDIR}/mk/tools/msgfmt-msgctxt.awk
STRIP_CMD.no=	${CAT}

GCONF_SCHEMAS=	ibus-chewing.schemas
CMAKE_ARGS+=	-DLIBEXEC_DIR=${PREFIX}/libexec
CMAKE_ARGS+=	-DGCONF_SCHEMAS_INSTALLED_DIR=${GCONF_SCHEMAS_DIR}

SUBST_CLASSES+=		localedir
SUBST_STAGE.localedir=	pre-configure
SUBST_VARS.localedir=	PKGLOCALEDIR
SUBST_FILES.localedir+=	Modules/ManageTranslation.cmake
SUBST_FILES.localedir+=	src/main.c

# missing in archive
post-extract:
	${TOUCH} ${WRKSRC}/po/ibus-chewing.pot

.include "../../devel/GConf/schemas.mk"
.include "../../inputmethod/ibus/buildlink3.mk"
.include "../../inputmethod/libchewing/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
