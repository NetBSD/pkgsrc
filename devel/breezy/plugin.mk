# $NetBSD: plugin.mk,v 1.2 2024/01/07 15:13:12 rhialto Exp $

BREEZY_PLUGIN_NAME?=		${PKGBASE:S/^breezy-//}
BREEZY_PLUGIN_TEST?=		yes
BREEZY_PLUGIN_TEST_DIR?=	${WRKSRC}/build/lib/breezylib/plugins

DEPENDS+=			breezy>=3.0:../../devel/breezy

# stolen from graphics/hicolor-icon-theme
.include "../../mk/bsd.fast.prefs.mk"

.if !defined(TEST_TARGET) && !empty(BREEZY_PLUGIN_TEST:M[Yy][Ee][Ss])
# stolen from breezy-svn
do-test:
	BREEZY_PLUGIN_PATH=${BREEZY_PLUGIN_TEST_DIR} brz selftest -v \
	  --starting-with=breezylib.plugins.${BREEZY_PLUGIN_NAME}
.endif
