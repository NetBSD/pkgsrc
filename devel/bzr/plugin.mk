# $NetBSD: plugin.mk,v 1.1 2008/08/26 01:17:33 epg Exp $

BZR_PLUGIN_NAME?=	${PKGBASE:S/^bzr-//}
BZR_PLUGIN_TEST?=	yes
BZR_PLUGIN_TEST_DIR?=	${WRKSRC}/build/lib/bzrlib/plugins

DEPENDS+=		bzr>=1.6:../../devel/bzr

# stolen from graphics/hicolor-icon-theme
.include "../../mk/bsd.fast.prefs.mk"
dirs!=	${GREP} '^@dirrm ${PYSITELIB}' ${.CURDIR}/../../devel/bzr/PLIST | \
	${CUT} -d ' ' -f 2 | ${SED} 's,\$${PYSITELIB},,'
.for d in ${dirs}
PRINT_PLIST_AWK+=	/^@dirrm ${PYSITELIB:S/\//\\\//g}${d:S/\//\\\//g}$$/ \
			{ \
			  sub(/${PYSITELIB:S/\//\\\//g}/, "$${PYSITELIB}"); \
			  print "@comment in bzr: " $$0; next; }
.endfor
.undef dirs

.if !defined(TEST_TARGET) && !empty(BZR_PLUGIN_TEST:M[Yy][Ee][Ss])
# stolen from bzr-svn
do-test:
	BZR_PLUGIN_PATH=${BZR_PLUGIN_TEST_DIR} bzr selftest -v \
	  --starting-with=bzrlib.plugins.${BZR_PLUGIN_NAME}
.endif
