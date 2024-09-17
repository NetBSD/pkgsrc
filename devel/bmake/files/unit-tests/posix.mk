# $NetBSD: posix.mk,v 1.5 2024/09/17 11:52:33 jperkin Exp $

all:	x plus subs err

x:
	@echo "Posix says we should execute the command as if run by system(3)"
	@echo "Expect 'Hello,' and 'World!'"
	@echo Hello,; false; echo "World!"

plus:
	@echo a command
	+@echo "a command prefixed by '+' executes even with -n"
	@echo another command

subs:
	@echo make -n
	@${.MAKE} -r -f ${MAKEFILE} -n plus
	@echo make -n -j1
	@${.MAKE} -r -f ${MAKEFILE} -n -j1 plus

err:
	@(echo Now we expect an error...; exit 1)
	@echo "Oops! you shouldn't see this!"
