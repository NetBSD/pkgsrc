# $NetBSD: tests.mk,v 1.1.2.3 2008/07/13 20:46:18 schmonz Exp $
#

TEST_TARGET=	test
TEST_DIRS=	tests
DEPENDS+=	atf-[0-9]*:../../devel/atf	# XXX should be TEST_DEPENDS

.include "../../mk/bsd.prefs.mk"

ECHOWRAPPER=			${ECHO}
WRAPPEES+=			ECHOWRAPPER
_WRAP_ALIASES.ECHOWRAPPER=	echowrapper

post-wrapper:
	${RM} -f ${WRAPPER_BINDIR}/${ECHOWRAPPER}

# XXX should just be TEST_ENV
MAKE_ENV+=	BUILDLINK_DIR=${BUILDLINK_DIR:Q}
MAKE_ENV+=	_USE_RPATH=${_USE_RPATH:Q}
MAKE_ENV+=	WRAPPER_DEBUG=yes

# The default transforms are already available to automated tests. To
# expose additional transforms to ATF, list them below:

.if ${LOCALBASE} != "/opt/schily"
BUILDLINK_TRANSFORM+=	rmdir:/opt/schily
.endif

BUILDLINK_TRANSFORM+=   l:readline:edit:termcap:m
