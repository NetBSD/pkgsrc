# $NetBSD: Makefile,v 1.9 2011/11/01 06:01:51 sbd Exp $
#

DISTNAME=	ibus-chewing-1.3.9.2-Source
PKGNAME=	${DISTNAME:S/-Source//}
PKGREVISION=	3
CATEGORIES=	inputmethod chinese
MASTER_SITES=	http://ibus.googlecode.com/files/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://code.google.com/p/ibus/
COMMENT=	Chewing engine for IBus input platform
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+=		gob2-[0-9]*:../../devel/gob2

USE_CMAKE=		yes
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgmerge pkg-config

SUBST_CLASSES+=		msgctxt
SUBST_STAGE.msgctxt=	post-extract
SUBST_FILES.msgctxt=	po/*.po po/*.pot
SUBST_FILTER_CMD.msgctxt=	${STRIP_CMD.${MSGFMT_STRIP_MSGCTXT}}
STRIP_CMD.yes=	${AWK} -f ${PKGSRCDIR}/mk/tools/msgfmt-msgctxt.awk
STRIP_CMD.no=	${CAT}

GCONF_SCHEMAS=	ibus-chewing.schemas
CMAKE_ARGS+=	-DGCONF_SCHEMAS_INSTALLED_DIR=${GCONF_SCHEMAS_DIR}

.include "../../devel/GConf/schemas.mk"
.include "../../inputmethod/ibus/buildlink3.mk"
.include "../../inputmethod/libchewing/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
