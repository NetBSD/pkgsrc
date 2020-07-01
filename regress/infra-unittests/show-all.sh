#! /bin/sh
# $NetBSD: show-all.sh,v 1.3 2020/07/01 09:13:12 rillig Exp $
#
# Tests for the show-all target from mk/misc/show.mk.
#
# Ensures that the show-all target prints all variants of variable
# values as intended.  This involves sorted multi-valued variables (like
# CONFIGURE_ENV), other multi-valued variables (like CONFIGURE_ARGS),
# variables containing special characters that need to be escaped, and
# various other edge cases.
#

. './test.subr'


if test_case_begin 'show all'; then

	# Ensures that the output of the show-all target is easily
	# recognizable by pkgsrc developers.
	#
	# The variable values are aligned in column 24 by default.  The
	# variable assignments have the same form as those that are
	# written in Makefiles.
	#
	# For lists of values, each value is written on a line of its
	# own, to aid readability.  The final line only contains the
	# comment marker, for ease of implementation.  This comment
	# marker also provides a convenient place for remarks like
	# "sorted" or "ends with space".

	create_file 'test.mk' <<'EOF'
REGRESS.empty=		# empty
REGRESS.space=		${:U } # a single space
REGRESS.value=		All * kinds of `strange' \escape $$characters

REGRESS_ENV.empty=	# empty
REGRESS_ENV.space=	${:U } # a single space
REGRESS_ENV.value=	VAR1=value1 VAR2=`command execution via backticks` *=all

REGRESS_ARGS.empty=	# empty
REGRESS_ARGS.space=	${:U } # a single space
REGRESS_ARGS.value=	VAR1=value1 VAR2=`command execution via backticks` *=all

# Variable names may also contain special characters that must be escaped.
#
# The "*" variable is built-in into bmake and expands to the current
# make target, which in this case is "show-all-regress".
#
# The "**" variable ensures that show-all doesn't accidentally expand
# filenames.
*=			bmake built-in
**=			asterisk

_VARGROUPS+=		regress
_PKG_VARS.regress+=	REGRESS_ENV.undefined REGRESS_ENV.empty REGRESS_ENV.space REGRESS_ENV.value
_PKG_VARS.regress+=	REGRESS_ARGS.undefined REGRESS_ARGS.empty REGRESS_ARGS.space REGRESS_ARGS.value
_PKG_VARS.regress+=	REGRESS.undefined REGRESS.empty REGRESS.space REGRESS.value
_PKG_VARS.regress+=	* **
_SORTED_VARS.regress=	*_ENV.*
_LISTED_VARS.regress=	*_ARGS.*

RUN=	@set -eu;
.include "${PKGSRCDIR}/mk/misc/show.mk"
EOF

	PKGSRCDIR="$pkgsrcdir" \
	"$make" -f 'test.mk' 'show-all-regress' 1> 'output' 2>&1 \
	&& exitcode=0 || exitcode=$?

	create_file 'expected' <<'EOF'
regress:
  pkg   REGRESS_ENV.undefined   # undefined
  pkg   REGRESS_ENV.empty=      # empty
  pkg   REGRESS_ENV.space=      # empty
  pkg   REGRESS_ENV.value=      \
                                *=all \
                                VAR1=value1 \
                                VAR2=`command \
                                backticks` \
                                execution \
                                via \
                                # end of REGRESS_ENV.value (sorted)
  pkg   REGRESS_ARGS.undefined  # undefined
  pkg   REGRESS_ARGS.empty=     # empty
  pkg   REGRESS_ARGS.space=     # empty
  pkg   REGRESS_ARGS.value=     \
                                VAR1=value1 \
                                VAR2=`command \
                                execution \
                                via \
                                backticks` \
                                *=all \
                                # end of REGRESS_ARGS.value
  pkg   REGRESS.undefined       # undefined
  pkg   REGRESS.empty=          # empty
  pkg   REGRESS.space=           # ends with space
  pkg   REGRESS.value=          All * kinds of `strange' \escape $$characters
  pkg   *=                      show-all-regress
  pkg   **=                     asterisk

EOF

	# On first sight it may seem strange that bmake doesn't handle
	# the backticks command as a single word. Luckily, this is a
	# rare case.
	#
	# On the other hand, if it did, bmake would also have to handle
	# variable expansion and all the other syntactic difficulties
	# from parsing shell commands, and that would be just too much.

	assert_that "$exitcode" --equals '0'
	assert_that 'output' --file-equals 'expected'

	test_case_end
fi


if test_case_begin 'show dollars in variable values'; then

	# Up to 2020-03-20, the output of the ENV and ARGS variables differed
	# a lot from the PLAIN variable.

	create_file 'test.mk' <<'EOF'
SHELLVAR_PLAIN=		"$$var $${var} $$other $$$$"
SHELLVAR_ENV=		"$$var $${var} $$other $$$$"
SHELLVAR_ARGS=		"$$var $${var} $$other $$$$"

_VARGROUPS+=		shellvar
_PKG_VARS.shellvar=	SHELLVAR_PLAIN SHELLVAR_ENV SHELLVAR_ARGS
_SORTED_VARS.shellvar=	*_ENV
_LISTED_VARS.shellvar=	*_ARGS

RUN=	@set -eu;
.include "${PKGSRCDIR}/mk/misc/show.mk"
EOF

	PKGSRCDIR="$pkgsrcdir" \
	"$make" -f 'test.mk' 'show-all-shellvar' 1> 'output' 2>&1 \
	&& exitcode=0 || exitcode=$?

	create_file 'expected' <<'EOF'
shellvar:
  pkg   SHELLVAR_PLAIN=         "$$var $${var} $$other $$$$"
  pkg   SHELLVAR_ENV=           \
                                "$$var $${var} $$other $$$$" \
                                # end of SHELLVAR_ENV (sorted)
  pkg   SHELLVAR_ARGS=          \
                                "$$var $${var} $$other $$$$" \
                                # end of SHELLVAR_ARGS

EOF

	assert_that "$exitcode" --equals '0'
	assert_that 'output' --file-equals 'expected'

	test_case_end
fi


if test_case_begin 'individual width'; then

	# If the variable names of a group are typically longer than 16
	# characters, it is possible to increase the width.

	create_file 'test.mk' <<'EOF'
VAR_PLAIN=		value
VAR_ENV=		value1 value2
VAR_ARGS=		value1 value2

_VARGROUPS+=		var
_VARGROUP_WIDTH.var=	15
_PKG_VARS.var=		VAR_PLAIN VAR_PLAIN_LONG_NAME
_PKG_VARS.var+=		VAR_ENV VAR_ENV_LONG_NAME
_PKG_VARS.var+=		VAR_ARGS VAR_ARGS_LONG_NAME
_SORTED_VARS.var=	*_ENV
_LISTED_VARS.var=	*_ARGS

RUN=	@set -eu;
.include "${PKGSRCDIR}/mk/misc/show.mk"
EOF

	PKGSRCDIR="$pkgsrcdir" \
	"$make" -f 'test.mk' 'show-all-var' 1> 'output' 2>&1 \
	&& exitcode=0 || exitcode=$?

	create_file 'expected' <<'EOF'
var:
  pkg   VAR_PLAIN=      value
  pkg   VAR_PLAIN_LONG_NAME # undefined
  pkg   VAR_ENV=        \
                        value1 \
                        value2 \
                        # end of VAR_ENV (sorted)
  pkg   VAR_ENV_LONG_NAME # undefined
  pkg   VAR_ARGS=       \
                        value1 \
                        value2 \
                        # end of VAR_ARGS
  pkg   VAR_ARGS_LONG_NAME # undefined

EOF

	assert_that "$exitcode" --equals '0'
	assert_that 'output' --file-equals 'expected'

	test_case_end
fi
