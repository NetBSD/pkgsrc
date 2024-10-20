# $NetBSD: Makefile,v 1.38 2024/10/20 14:03:29 wiz Exp $

DISTNAME=	srain-1.7.0
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=SrainApp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://srain.im/
COMMENT=	Modern IRC client written in GTK
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx

USE_TOOLS+=	msgfmt msgmerge pkg-config xgettext

PYTHON_VERSIONS_INCOMPATIBLE=	39 # py-sphinx

MESON_ARGS+=	-Dapp_indicator=false
MESON_ARGS+=	-Ddoc_builders=man

OWN_DIRS+=	${PKG_SYSCONFDIR}/srain

EGDIR=		${PREFIX}/share/examples/srain
CONF_FILES=	${EGDIR}/builtin.cfg ${PKG_SYSCONFDIR}/srain/builtin.cfg

SUBST_CLASSES+=		sphinx
SUBST_STAGE.sphinx=	pre-configure
SUBST_FILES.sphinx=	docs/meson.build
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
.include "../../net/libsoup3/buildlink3.mk"
.include "../../security/libsecret/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
