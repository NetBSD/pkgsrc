# $NetBSD: replace.mk,v 1.1.1.1 2004/11/27 13:57:21 taca Exp $
#

.ifndef _RUBY_REPLACE_MK
_RUBY_REPLACE_MK=	# defined

# fix shebang line.
#
# REPLACE_RUBY		replace shebang line of specified files.
# REPLACE_RUBY_DIRS	replace shebang line of files under specified
#			directories.
# REPLACE_FILE_PAT	specify pattern to match target files under
#			REPLACE_RUBY_DIRS directories.
#
REPLACE_FILE_PAT?=	*.rb

.if defined(REPLACE_RUBY) || defined(REPLACE_RUBY_DIRS)
pre-configure: replace-ruby-scripts replace-ruby-dirs

.if defined(REPLACE_RUBY) && !empty(REPLACE_RUBY)
replace-ruby-scripts:
	${_PKG_SILENT}${_PKG_DEBUG}for s in ${REPLACE_RUBY}; do \
		case $${s} in \
		/*)	f=$${s};; \
		*)	f=${WRKSRC}/$${s};; \
		esac; \
		${ECHO_MSG} "===>  Fixing the #! line of $${s}"; \
		${SED}	-e '1s| *[a-z0-9_/\.-][a-z0-9_/\.-]*/env *||g' \
			-e '1s| *[a-z0-9_/\.-]*ruby|${RUBY}|' $$f > $$f.tmp; \
		if ${CMP} -s $$f $$f.tmp; then \
			${RM} $$f.tmp; \
		else \
			${MV} $$f.tmp $$f; \
		fi; \
	done
.else
replace-ruby-scripts:
.endif

.for f in ${REPLACE_FILE_PAT}
_REPLACE_FILE_PAT+= -o -name "${f}"
.endfor
_REPLACE_FILE_FIND_ARGS=\( ${_REPLACE_FILE_PAT:S/-o//1} \)

.if defined(REPLACE_RUBY_DIRS) && !empty(REPLACE_RUBY_DIRS)
replace-ruby-dirs:
	${_PKG_SILENT}${_PKG_DEBUG}${FIND} ${REPLACE_RUBY_DIRS} \
	    -type f ${_REPLACE_FILE_FIND_ARGS} -print | \
	    while read f; do \
		${SED}	-e '1s| *[a-z0-9_/\.-][a-z0-9_/\.-]*/env *||g' \
			-e '1s| *[a-z0-9_/\.-]*ruby|${RUBY}|' $$f > $$f.tmp; \
		if ${CMP} -s $$f $$f.tmp; then \
			${RM} $$f.tmp; \
		else \
			${MV} $$f.tmp $$f; \
		fi; \
	    done
.else
replace-ruby-dirs:
.endif

.endif # defined(REPLACE_RUBY) || defined(REPLACE_RUBY_DIRS)
.endif # _RUBY_REPLACE_MK
