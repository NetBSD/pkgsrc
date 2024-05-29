# $NetBSD: Makefile,v 1.34 2024/05/29 16:31:32 adam Exp $

DISTNAME=	srain-1.3.2
PKGREVISION=	16
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=SrainApp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://srain.im/
COMMENT=	Modern IRC client written in GTK
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

USE_TOOLS+=	pkg-config
USE_TOOLS+=	msgfmt msgmerge xgettext

MESON_ARGS+=	-Ddoc_builders=man

OWN_DIRS+=	${PKG_SYSCONFDIR}/srain

EGDIR=		${PREFIX}/share/examples/srain
CONF_FILES=	${EGDIR}/builtin.cfg ${PKG_SYSCONFDIR}/srain/builtin.cfg

SUBST_CLASSES+=		sphinx
SUBST_STAGE.sphinx=	pre-configure
SUBST_FILES.sphinx=	doc/meson.build
SUBST_MESSAGE.sphinx=	Fixing sphinx binary name.
SUBST_SED.sphinx+=	-e "s,sphinx-build,sphinx-build-${PYVERSSUFFIX},"

PYTHON_FOR_BUILD_ONLY=	tool

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/share/srain/themes/meson.build

.include "../../lang/python/pyversion.mk"
.include "../../devel/meson/build.mk"
.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../devel/libconfig/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../security/libsecret/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
