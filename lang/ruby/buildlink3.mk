# $NetBSD: buildlink3.mk,v 1.10 2009/03/20 19:24:52 joerg Exp $

.if !defined(_RUBYVERSION_MK)
.include "../../lang/ruby/rubyversion.mk"
.endif

BUILDLINK_TREE+=	${RUBY_BASE}

.if !defined(RUBY_BUILDLINK3_MK)
RUBY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.${RUBY_BASE}?=	${RUBY_BASE}>=${RUBY_REQD}
BUILDLINK_ABI_DEPENDS.${RUBY_BASE}?=	${RUBY_BASE}>=${RUBY_VERSION}
BUILDLINK_PKGSRCDIR.${RUBY_BASE}?=	../../lang/${RUBY_BASE}
BUILDLINK_FILES.${RUBY_BASE}+=		lib/libruby${RUBY_VER}.*
BUILDLINK_FILES.${RUBY_BASE}+=	lib/ruby/${RUBY_VER_DIR}/${RUBY_ARCH}/*.h

BUILDLINK_TARGETS+=	buildlink-bin-ruby

buildlink-bin-ruby:
	${_PKG_SILENT}${_PKG_DEBUG} \
	f=${BUILDLINK_PREFIX.${RUBY_BASE}:Q}"/bin/ruby${RUBY_VER}"; \
	if ${TEST} -f $$f; then \
		${LN} -s $$f ${BUILDLINK_DIR}/bin/ruby; \
	fi
.endif # RUBY_BUILDLINK3_MK

BUILDLINK_TREE+=	-${RUBY_BASE}
