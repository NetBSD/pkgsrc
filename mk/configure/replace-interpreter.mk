# $NetBSD: replace-interpreter.mk,v 1.1 2006/07/05 06:09:15 jlam Exp $

######################################################################
### replace-interpreter (PRIVATE)
######################################################################
### replace-interpreter replaces paths to interpreters in scripts with
### the paths to the pkgsrc-managed interpreters.
###
do-configure-pre-hook: replace-interpreter

.if defined(REPLACE_PERL)
REPLACE_INTERPRETER+=	perl
REPLACE.perl.old=	.*/bin/perl
REPLACE.perl.new=	${PERL5}
REPLACE_FILES.perl=	${REPLACE_PERL}
.endif

# XXX After 2006Q2, all instances of _REPLACE.* and _REPLACE_FILES.* should
# XXX have been replaced with REPLACE.* and REPLACE_FILES.*. This code is
# XXX then no longer needed.
# XXX
.for _lang_ in ${REPLACE_INTERPRETER}
REPLACE.${_lang_}.old?=		${_REPLACE.${_lang_}.old}
REPLACE.${_lang_}.new?=		${_REPLACE.${_lang_}.new}
REPLACE_FILES.${_lang_}?=	${_REPLACE_FILES.${_lang_}}
.endfor

.PHONY: replace-interpreter
replace-interpreter:
.for _lang_ in ${REPLACE_INTERPRETER}
	@${STEP_MSG} "Replacing interpreter paths in scripts"
.  for _pattern_ in ${REPLACE_FILES.${_lang_}}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	cd ${WRKSRC};							\
	for file in ${_pattern_}; do					\
		if ${TEST} ! -f "$$file"; then				\
			${WARNING_MSG} "[replace-interpreter.mk] Skipping non-existent file \"$$file\"."; \
			continue;					\
		fi;							\
		${SED} -e '1s|^#!${REPLACE.${_lang_}.old}|#!${REPLACE.${_lang_}.new}|' \
			$$file > $$file.new;				\
		if ${TEST} -x $$file; then				\
			${CHMOD} a+x $$file.new;			\
		fi;							\
		${MV} -f $$file.new $$file;				\
	done
.  endfor
.endfor
