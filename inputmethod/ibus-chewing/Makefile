# $NetBSD: Makefile,v 1.66 2020/06/02 08:24:09 adam Exp $
#

DISTNAME=	ibus-chewing-1.4.12-Source
PKGNAME=	${DISTNAME:S/-Source//}
PKGREVISION=	24
CATEGORIES=	inputmethod chinese
MASTER_SITES=	https://github.com/definite/ibus-chewing/releases/download/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ibus/ibus/wiki
COMMENT=	Chewing engine for IBus input platform
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=		gob2-[0-9]*:../../devel/gob2

USE_CMAKE=		yes
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt pkg-config
TOOLS_NOOP+=		msgmerge xgettext

BUILD_TARGET=	all translations

SUBST_CLASSES+=		libexecdir
SUBST_STAGE.libexecdir=	post-configure
SUBST_FILES.libexecdir=	data/ibus-setup-chewing.desktop
SUBST_SED.libexecdir=	-e 's,/usr/libexec/,${PREFIX}/libexec/,g'

TEST_TARGET=	test

.include "../../devel/glib2/schemas.mk"

.include "../../devel/glib2/buildlink3.mk"
.include "../../inputmethod/ibus/buildlink3.mk"
.include "../../inputmethod/libchewing/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
