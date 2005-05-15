# $NetBSD: quoting.mk,v 1.1.1.1 2005/05/15 21:10:16 rillig Exp $
#
# This file demonstrates various techniques for quoting variables when
# passing them to the shell.
#

EVIL_STRING?=	"   "

.PHONY: all
all:
	echo ${EVIL_STRING}
	echo ${EVIL_STRING:Q}
	echo "${EVIL_STRING}"
	echo "${EVIL_STRING:Q}"
	echo ${EVIL_STRING:Q}""
	echo x${EVIL_STRING:Q} | sed 1s,.,,
