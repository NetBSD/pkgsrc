# $NetBSD: bsd.pkg.help.mk,v 1.3 2006/08/02 10:50:00 rillig Exp $
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
_HELP_FILES+=		mk/*/*.mk

_HELP_AWK= \
	BEGIN {								\
		no = 0; yes = 1;					\
		hline = "===============";				\
		hline = hline hline hline hline hline;			\
		found = no; var = no; comment = no; n = 0;		\
		rcsid = "";						\
		last_line_was_rcsid = no;				\
		last_line_was_empty = yes;				\
	}								\
	/./ {								\
		if ($$0 ~ /^\\#.*\$$.*\$$$$/) {				\
			rcsid = $$0;					\
			last_line_was_rcsid = yes;			\
		} else {						\
			if (!(last_line_was_rcsid && $$0 == "\#")) {	\
				lines[n++] = $$0;			\
			}						\
			last_line_was_rcsid = no;			\
		}							\
	}								\
	($$1 == VARNAME"?=") || ($$1 == "\#"VARNAME"=") 		\
	|| ($$1 == "\#" && $$2 == VARNAME && last_line_was_empty) {	\
		var = 1;						\
	}								\
	/^\#/ {								\
		comment = 1;						\
	}								\
	/^$$/ {								\
		if (var && comment) {					\
			found = yes;					\
			print hline;					\
			if (rcsid != "") { print rcsid; print "\#"; }	\
			for (i = 0; i < n; i++) { print lines[i]; }	\
		}							\
		var = no; comment = no; n = 0;				\
	}								\
	/./ {								\
		last_line_was_empty = no;				\
	}								\
	/^\\#$$/ || /^$$/ {						\
		last_line_was_empty = yes;				\
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

.PHONY: help
help:
.if !defined(TOPIC)
	@${ECHO} "usage: "${MAKE:Q}" help TOPIC=<VARNAME>" 1>&2
.else
	${_PKG_SILENT}${_PKG_DEBUG} set -e;				\
	cd ${PKGSRCDIR};						\
	{ for i in ${_HELP_FILES}; do ${CAT} "$$i"; ${ECHO} ""; done; }	\
	| ${AWK} -v VARNAME=${TOPIC} '${_HELP_AWK}'
.endif

.endif
