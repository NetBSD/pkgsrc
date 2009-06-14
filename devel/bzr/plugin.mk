# $NetBSD: plugin.mk,v 1.2 2009/06/14 22:57:59 joerg Exp $

BZR_PLUGIN_NAME?=	${PKGBASE:S/^bzr-//}
BZR_PLUGIN_TEST?=	yes
BZR_PLUGIN_TEST_DIR?=	${WRKSRC}/build/lib/bzrlib/plugins

DEPENDS+=		bzr>=1.6:../../devel/bzr

# stolen from graphics/hicolor-icon-theme
.include "../../mk/bsd.fast.prefs.mk"

.if !defined(TEST_TARGET) && !empty(BZR_PLUGIN_TEST:M[Yy][Ee][Ss])
# stolen from bzr-svn
do-test:
	BZR_PLUGIN_PATH=${BZR_PLUGIN_TEST_DIR} bzr selftest -v \
	  --starting-with=bzrlib.plugins.${BZR_PLUGIN_NAME}
.endif
