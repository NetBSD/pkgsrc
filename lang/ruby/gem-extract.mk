# $NetBSD: gem-extract.mk,v 1.1 2015/03/08 14:41:12 taca Exp $
#
# This Makefile fragment is intended to be included by packages that extract
# Ruby gems files.
.if !defined(_RUBYGEM_EXTRACT_MK)
_RUBYGEM_EXTRACT_MK=	# defined

.include "../../lang/ruby/rubyversion.mk"
.include "../../lang/ruby/gem-vars.mk"

_GEM_DISTFILES=		${DISTFILES:M*.gem}

###
### gem-extract
###
### The gem-extract target extracts a standard gem file.  It is an
### automatic dependency for the post-extract target so it doesn't
### disturb the usual do-extract actions.
###
.PHONY: gem-extract
post-extract: gem-extract
.if !target(gem-extract)
gem-extract: fake-home
.  for _gem_ in ${_GEM_DISTFILES}
	${RUN} cd ${WRKDIR} && ${SETENV} ${MAKE_ENV} ${RUBYGEM_ENV} \
		${RUBYGEM} unpack ${_DISTDIR:Q}/${_gem_:Q}
	${RUN} cd ${WRKDIR} && \
		${SETENV} ${MAKE_ENV} TZ=UTC ${RUBYGEM_ENV} \
		${RUBYGEM} spec --ruby ${_DISTDIR:Q}/${_gem_:Q} > ${_gem_}spec
.  endfor
.endif

.endif
