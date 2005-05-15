# $NetBSD: vtarget.mk,v 1.1.1.1 2005/05/15 21:10:16 rillig Exp $
#
# This file demonstrates that the ${.TARGET} variable does not have to
# be quoted when the target is specified by a quoted variable.
#

FOO=		a    b `date`

${FOO:Q}:
	echo ${.TARGET}
