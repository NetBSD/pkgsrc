# $NetBSD: tests.mk,v 1.1.2.2 2008/07/13 17:55:13 schmonz Exp $
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

# Record transforms to be tested below. Then create corresponding ATF tests
# in files/tests.

# Remove /opt/schily.
.if ${LOCALBASE} != "/opt/schily"
BUILDLINK_TRANSFORM+=	rmdir:/opt/schily
.endif

# Convert "-lreadline" into "-ledit -ltermcap -lm".
BUILDLINK_TRANSFORM+=   l:readline:edit:termcap:m
