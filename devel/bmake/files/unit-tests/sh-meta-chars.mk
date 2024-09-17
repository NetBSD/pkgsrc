# $NetBSD: sh-meta-chars.mk,v 1.2 2024/09/17 11:52:33 jperkin Exp $
#
# Tests for running shell commands that contain meta-characters.
#
# These meta-characters decide whether the command is run by the shell
# or executed directly via execv, but only in compatibility mode, not
# in jobs mode, and only if MAKE_NATIVE is defined during compilation.
#
# See also:
#	Compat_RunCommand, useShell

all:

# The command "exit 0" contains no special characters, therefore it is
# run directly via execv, but only if MAKE_NATIVE is defined.
USING_EXEC!=	{ echo 'all:; exit 0' | ${MAKE} -r -f - 1>/dev/null 2>&1; } \
		&& echo yes || echo no

# It's hard to do any useful tests that result in the same output.
# See SED_CMDS.sh-dots, which normalizes the test output for the specific
# case of the special command '...'.
.if ${USING_EXEC} != "yes" && ${USING_EXEC} != "no"
.  error
.endif
