# $NetBSD: cond-func-commands.mk,v 1.2 2024/09/17 11:52:29 jperkin Exp $
#
# Tests for the commands() function in .if conditions.

.MAIN: all

# At this point, the target 'target' does not exist yet, therefore it cannot
# have commands.  Sounds obvious, but good to know that it is really so.
.if commands(target)
.  error
.endif

target:

# Now the target exists, but it still has no commands.
.if commands(target)
.  error
.endif

target:
	# not a command

# Even after the comment, the target still has no commands.
.if commands(target)
.  error
.endif

target:
	@:;

# Finally the target has commands.
.if !commands(target)
.  error
.endif

all:
	@:;
