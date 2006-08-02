# $NetBSD: bsd.pkg.help.mk,v 1.1 2006/08/02 09:46:22 rillig Exp $
#

# This is the integrated pkgsrc online help system. To query for the
# meaning of a variable, run "make help TOPIC=VARNAME". All variables from
# certain pkgsrc Makefile fragments that have inline comments are eligible
# for querying.

.if !defined(_PKGSRC_HELP_MK)
_PKGSRC_HELP_MK=	# defined

_HELP_FILES=		# empty
_HELP_FILES+=		mk/defaults/mk.conf
_HELP_FILES+=		mk/bsd.prefs.mk
_HELP_FILES+=		mk/bsd.pkg.mk
_HELP_FILES+=		mk/*/*-vars.mk

_HELP_AWK= \
	BEGIN {								\
		hline = "===============";				\
		hline = hline hline hline hline hline;			\
		found = 0;						\
		var = 0; comment = 0; n = 0; lines[n++] = hline;	\
	}								\
	/./ {								\
		lines[n++] = $$0;					\
	}								\
	($$1 == VARNAME"?=") || ($$1 == "\#"VARNAME"=") {		\
		var = 1;						\
	}								\
	/^\#/ {								\
		comment = 1;						\
	}								\
	/^$$/ {								\
		if (var == 1 && comment == 1) {				\
			found = 1;					\
			for (i = 0; i < n; i++) { print lines[i]; }	\
		}							\
		var = 0; comment = 0; n = 0; lines[n++] = hline;	\
	}								\
	END {								\
		if (found) {						\
			print hline;					\
		} else {						\
			print "No help found for " VARNAME ".";		\
		}							\
	}

.if !defined(TOPIC) && defined(VARNAME)
TOPIC=		${VARNAME}
.endif

help:
.if !defined(TOPIC)
	@${ECHO} "usage: "${MAKE:Q}" help TOPIC=<VARNAME>" 1>&2
.else
	@set -e; cd ${PKGSRCDIR};					\
	{ for i in ${_HELP_FILES}; do ${CAT} "$$i"; ${ECHO} ""; done; }	\
	| ${AWK} -v VARNAME=${TOPIC} '${_HELP_AWK:M*}'
.endif

.endif
