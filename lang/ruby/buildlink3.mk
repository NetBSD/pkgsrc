# $NetBSD: buildlink3.mk,v 1.18 2014/03/13 17:06:42 taca Exp $

BUILDLINK_TREE+=	${RUBY_BASE}

.if !defined(RUBY_BUILDLINK3_MK)
RUBY_BUILDLINK3_MK:=

.if !defined(_RUBYVERSION_MK)
.include "../../lang/ruby/rubyversion.mk"
.endif

BUILDLINK_API_DEPENDS.${RUBY_BASE}+=	${RUBY_BASE}>=${RUBY_VERSION}
BUILDLINK_ABI_DEPENDS.${RUBY_BASE}+=	${RUBY_BASE}>=${RUBY_ABI_VERSION}
BUILDLINK_PKGSRCDIR.${RUBY_BASE}?=	${RUBY_SRCDIR}
BUILDLINK_FILES.${RUBY_BASE}+=		lib/libruby${RUBY_SUFFIX}.*
BUILDLINK_FILES.${RUBY_BASE}+=	lib/ruby/${RUBY_VER_DIR}/${RUBY_ARCH}/*.h

BUILDLINK_TARGETS+=	buildlink-bin-ruby

buildlink-bin-ruby:
	${RUN} \
	f=${BUILDLINK_PREFIX.${RUBY_BASE}:Q}"/bin/ruby${RUBY_SUFFIX}"; \
	if ${TEST} -f $$f; then \
		${LN} -s $$f ${BUILDLINK_DIR}/bin/ruby; \
	fi

.if empty(RUBY_USE_PTHREAD:M[nN][oO])
PTHREAD_OPTS+=		native
PTHREAD_AUTO_VARS=	yes

.include "../../mk/pthread.buildlink3.mk"
.endif
.include "../../mk/dlopen.buildlink3.mk"

.endif # RUBY_BUILDLINK3_MK

BUILDLINK_TREE+=	-${RUBY_BASE}
