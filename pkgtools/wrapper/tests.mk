# $NetBSD: tests.mk,v 1.1.2.1 2008/07/12 04:49:17 schmonz Exp $
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

# Record transforms to be tested below. Then create corresponding ATF tests
# in files/tests.

# Remove /opt/schily.
.if ${LOCALBASE} != "/opt/schily"
BUILDLINK_TRANSFORM+=	rmdir:/opt/schily
.endif

# Convert "-lreadline" into "-ledit -ltermcap -lm".
BUILDLINK_TRANSFORM+=   l:readline:edit:termcap:m
